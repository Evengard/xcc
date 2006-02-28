// palet_filter.h: interface for the Cpalet_filter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PALET_FILTER_H__134A6500_124E_11D6_B85F_0000B4936994__INCLUDED_)
#define AFX_PALET_FILTER_H__134A6500_124E_11D6_B85F_0000B4936994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include <vector>
#include "cc_file.h"
#include "cc_structures.h"
#include "xif_key.h"

class Cpalet_filter  
{
public:
	string pick(t_game& game);
	void select(t_file_type ft, int cx, int cy, string fname);
	Cpalet_filter();
private:
	class Clist_entry
	{
	public:
		Clist_entry(t_game game, string palet, t_file_type ft, string fname = "", int cx = 0, int cy = 0)
		{
			m_game = game;
			m_palet = palet;
			m_ft = ft;
			m_fname = fname;
			m_cx = cx;
			m_cy = cy;
		}

		t_game game() const
		{
			return m_game;
		}

		string palet() const
		{
			return m_palet;
		}
		
		int q(t_file_type ft, int cx, int cy, string fname) const;
	private:
		int m_cx;
		int m_cy;
		string m_fname;
		t_file_type m_ft;
		t_game m_game;
		string m_palet;
	};

	typedef list<Clist_entry> t_list;
	typedef vector<t_list::const_iterator> t_vector;

	t_list m_list;
	t_vector::const_iterator m_vector_i;
	t_vector m_vector;
};

#endif // !defined(AFX_PALET_FILTER_H__134A6500_124E_11D6_B85F_0000B4936994__INCLUDED_)