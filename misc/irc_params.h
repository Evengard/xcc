// irc_params.h: interface for the Circ_params class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IRC_PARAMS_H__74135060_212F_11D5_A95E_0050042229FC__INCLUDED_)
#define AFX_IRC_PARAMS_H__74135060_212F_11D5_A95E_0050042229FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

class Circ_params  
{
public:
	void clear();
	string read() const;
	static string strip(const string&);
	void write(const string& v);
	const string& prefix() const;
	string prefix_nick() const;
	string prefix_user() const;
	string prefix_host() const;
	const string& p(int i) const;
	bool p_equal(int i, const string& v) const;
	int p_int(int i) const;
	void p(int i, const string& v);
	void p(int i, int v);

	int count() const
	{
		return m_params.size();
	}
private:
	typedef vector<string> t_params;

	string m_prefix;
	t_params m_params;
};

#endif // !defined(AFX_IRC_PARAMS_H__74135060_212F_11D5_A95E_0050042229FC__INCLUDED_)