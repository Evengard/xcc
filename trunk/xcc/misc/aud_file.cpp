// aud_file.cpp: implementation of the Caud_file class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "aud_file.h"

#include <cassert>
#include "aud_decode.h"
#include "wav_structures.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool Caud_file::is_valid()
{
	if (sizeof(t_aud_header) > get_size() ||
		m_header.samplerate < 8000 || m_header.samplerate > 48000 ||
		m_header.size_in != get_size() - sizeof(t_aud_header))
		return false;
	switch (m_header.compression)
	{
	case 1:
		return m_header.flags == 0;
	case 0x63:
		return m_header.flags == 2;
	}
	return false;
}

const t_aud_chunk_header* Caud_file::get_chunk_header(int i)
{
	assert(is_open());
	if (!get_data())
		read();
	const byte* r = get_data() + sizeof(t_aud_header);
	while (i--)
	{
		const t_aud_chunk_header* header = reinterpret_cast<const t_aud_chunk_header*>(r);
		r += sizeof(t_aud_chunk_header) + header->size_in;
	}
	return reinterpret_cast<const t_aud_chunk_header*>(r);
}

const byte* Caud_file::get_chunk_data(int i)
{
	return reinterpret_cast<const byte*>(get_chunk_header(i)) + sizeof(t_aud_chunk_header);
}

int Caud_file::extract_as_wav(const string& name)
{
	int error = 0;
	Cfile32 f;
	error = f.open(name, GENERIC_WRITE);
	if (!error)
	{
		int cb_sample = get_cb_sample();
		int cs_remaining = get_c_samples();	
		t_wav_header header;
		memset(&header, 0, sizeof(t_wav_header));
		header.file_header.id = wav_file_id;
		header.file_header.size = sizeof(header) - sizeof(header.file_header) + (cs_remaining << 1);
		header.form_type = wav_form_id;
		header.format_chunk.header.id = wav_format_id;
		header.format_chunk.header.size = sizeof(header.format_chunk) - sizeof(header.format_chunk.header);
		header.format_chunk.formattag = 1;
		header.format_chunk.c_channels = 1;
		header.format_chunk.samplerate = get_samplerate();
		header.format_chunk.byterate =  cb_sample * get_samplerate();
		header.format_chunk.blockalign = cb_sample;
		header.format_chunk.cbits_sample = cb_sample << 3;
		header.data_chunk_header.id = wav_data_id;
		header.data_chunk_header.size = cb_sample * cs_remaining;
		error = f.write(&header, sizeof(t_wav_header));
		if (!error)
		{			
			int chunk_i = 0;
			aud_decode decode;
			decode.init();
			const byte* s;
			short d[1024];
			while (cs_remaining)
			{				
				const t_aud_chunk_header& header = *get_chunk_header(chunk_i);
				int cs_chunk = header.size_out / cb_sample;
				s = get_chunk_data(chunk_i++);
				decode.decode_chunk(s, d, cs_chunk);
				error = f.write(d, cb_sample * cs_chunk);
				cs_remaining -= cs_chunk;
				if (error)
					break;
			}			
		}
		f.close();
	}
	return error;
}
