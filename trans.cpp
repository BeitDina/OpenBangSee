//////////////////////////////////////////////////////////////////////////
//  Open BangSee Phonetic Parsing Library 2.0
//   
//
//  Released Under Lesser GNU Public License
//  
//  Copyright: Rahat Ayub (windows@gmail.com)
//  Developers: S Newaj and A.I. Munna
//  
//  Although this part of the code is written in C/C++ 
//  with Microsft Foundation Class library, it is totally
//  Compliant to Java String class. 
//  
//  This is done over Adarshabangla font, but please note that
//  it could be used for any ANSI Bangla font. Change respective
//  Code points as you desire.
// 
//  
//////////////////////////////////////////////////////////////////////////



#include "stdafx.h"
#include "trans.h"

String BSParseVowel(String s, int i);
String BSParseSound(String s, int i);
String BSParseSyllable(String s, int i);
String Replace(String s, char *s1, char *s2);

//////////////////////////////////////////////////////////////////////////
//
// Function:		BSParser
//
// Description:		Main parsing engine
//
// INPUTS:          Phonetic English String
// 
// RETURNS:         Parsed Bangla CodePoints (Adarsha Bangla)
//
// NOTES:			Anyone can change code points to Sutonny or AdarshaLipi etc.
// 
// MODIFICATIONS:
//
// Name                     Date        Version Comments
// Shah Ali Newaj Topu		26/08/2001    1.0     
// Shah Ali Newaj Topu		12/11/2001    1.1     
// A.I Munna				17/06/2002    1.2     
//
//////////////////////////////////////////////////////////////////////////
String BSParser(String s)
    {
        String s1;
        String s2;
        String s3;
		s1="";
		s2="";
		s3="";
        boolean flag = false;
        boolean flag1 = false;
        int i = 0;
        s = Replace(s, "~", " ");
        s = Replace(s, "<", " ");
        s = Replace(s, ">", " ");
        s = Replace(s, ".\n", "|\n");
        s = Replace(s, "z", "j");
        s = Replace(s, "q", "k");
        s = Replace(s, "ngl", "ng_l");
        s = Replace(s, "oo", "u");
        s = Replace(s, "ee", "i");
        s = Replace(s, "bh", "v");
        s = Replace(s, "ph", "f");
        s = Replace(s, "sk", "Sk");
        s = Replace(s, "sc", "Sk");
        s = Replace(s, "shth", "sth");
        s = Replace(s, "Sth", "sth");
        s = Replace(s, "sn", "Sn");
        s = Replace(s, "shn", "Sn");
        s = Replace(s, "o", "~");
        s = Replace(s, "Oi", "<");
        s = Replace(s, "Ou", ">");
        s = Replace(s, ". ", "| ");
        if(s.endsWith("."))
            s = s.substring(0, s.length() - 1) + "|";
        s2 = "";
        while(!s.equals("")) 
        {
            String s4 = s.substring(0, 1);
            s2 = s2 + s4;
            if(s4.equals(" ") || s4.equals("\n"))
            {
                i = 0;
                s1 = s1 + BSParseSyllable(s2, i);
                s2 = "";
            } else
            if(s4.equals("~") || s4.equals("<") || s4.equals(">") || s4.equals("a") || s4.equals("i") || s4.equals("I") || s4.equals("u") || s4.equals("U") || s4.equals("e") ||  s4.equals("O"))
            {
                i++;
                s1 = s1 + BSParseSyllable(s2, i);
                s2 = "";
            } else
            if(s4.equals("\n") || s4.equals("\"") || s4.equals("!") || s4.equals("1") || s4.equals("2") || s4.equals("3") || s4.equals("4") || s4.equals("5") || s4.equals("6") || s4.equals("7") || s4.equals("8") || s4.equals("9") || s4.equals("0") || s4.equals("?") || s4.equals(","))
            {
                i = 0;
                s1 = s1 + BSParseSyllable(s2, i);
                s2 = "";
            }
            if(s.length() > 1)
                s = s.substring(1);
            else
                s = "";
        }
        if(!s2.equals(""))
        {
            i++;
            s1 = s1 + BSParseSyllable(s2, i);
            s2 = "";
        }
        s1 = Replace(s1, "+L}", "+H@");
        s1 = Replace(s1, "a}", ")");
        s1 = Replace(s1, "L}", ")@");
        return s1;
    }

//////////////////////////////////////////////////////////////////////////
//
// Function:		BSParseSyllable
//
// Description:		Split phonetic word into syllable components
//
// INPUTS:          Phonetic English String, length of the string
// 
// RETURNS:         Parsed Bangla CodePoints (Adarsha Bangla)
//
// NOTES:			Anyone can change code points to Sutonny or AdarshaLipi etc.
// 
// MODIFICATIONS:
//
// Name                     Date        Version Comments
// Shah Ali Newaj Topu		26/08/2001    1.0     
// Shah Ali Newaj Topu		12/11/2001    1.1     
// A.I Munna				17/06/2002    1.2     
//
//////////////////////////////////////////////////////////////////////////

String BSParseSyllable(String s, int i)
{
        String s1;
        String s3;
        String s4;
        String s6;
        String s7;
		s1="";
		s3="";
		s4="";
		s6="";
		s7="";
        if(s.length() > 0)
            s7 = s.substring(s.length() - 1);
        if(s7.equals("~") || s7.equals("<") || s7.equals(">") || s7.equals("a") || s7.equals("i") || s7.equals("I") || s7.equals("u") || s7.equals("U") || s7.equals("e") ||  s7.equals("O"))
        {
            s3 = s7;
            s = s.substring(0, s.length() - 1);
        }
        while(!s.equals("")) 
        {
            String s2;
			s2="";
            if(s.length() > 1 && !s.equals("mm") && !s3.equals("") && !s.substring(s.length() - 2, s.length() - 1).equals("_") && (s.substring(s.length() - 1).equals("R") || s.substring(s.length() - 1).equals("r") || s.substring(s.length() - 1).equals("y") || s.substring(s.length() - 1).equals("w") || s.substring(s.length() - 1).equals("^") || s.substring(s.length() - 1).equals("m") || s.substring(s.length() - 1).equals("Y")))
            {
                s3 = s.substring(s.length() - 1) + s3;
                s = s.substring(0, s.length() - 1);
            }
            if(s.length() > 3)
            {
                String s8 = s.substring(s.length() - 4);
                if(s8.equals("dhdh") || s8.equals("shkh") || s8.equals("shph") || s8.equals("Shch") || s8.equals("ShCh") || s8.equals("sHph") || s8.equals("sHTh") || s8.equals("khkh") || s8.equals("chch"))
                {
                    s2 = s8;
                    s = s.substring(0, s.length() - 4);
                }
            }
            if(s.length() > 2 && s2.equals(""))
            {
                String s9 = s.substring(s.length() - 3);
                if(s9.equals("sHn") || s9.equals("tth") || s9.equals("Shn") || s9.equals("sHY") || s9.equals("cCh") || s9.equals("cch") || s9.equals("kkh") || s9.equals("ksh") || s9.equals("sth") || s9.equals("phl") || s9.equals("ngh") || s9.equals("nch") || s9.equals("ddh") || s9.equals("dbh") || s9.equals("nth") || s9.equals("nTh") || s9.equals("ndh") || s9.equals("nDh") || s9.equals("psh") || s9.equals("bdh") || s9.equals("mph") || s9.equals("lbh") || s9.equals("sHk") || s9.equals("sHT") || s9.equals("sHp") || s9.equals("sHf") || s9.equals("sHm") || s9.equals("shk") || s9.equals("Skh") || s9.equals("shp") || s9.equals("shf") || s9.equals("gdh") || s9.equals("chs") || s9.equals("jjh") || s9.equals("Nth") || s9.equals("NDh"))
                {
                    s2 = s9;
                    s = s.substring(0, s.length() - 3);
                }
            }
            if(s.length() > 1 && s2.equals(""))
            {
                String s10 = s.substring(s.length() - 2);
                if(s3.equals("") && s10.equals("ng"))
                {
                    s2 = "<ng>";
                    s = s.substring(0, s.length() - 2);
                } else
                if(s10.equals("pn") || s10.equals("pl") || s10.equals("bl") || s10.equals("Sn") || s10.equals("gn") || s10.equals("gN") || s10.equals("bj") || s10.equals("mn") || s10.equals("tn") || s10.equals("hN") || s10.equals("Rh") || s10.equals("gl") || s10.equals("fl") || s10.equals("kl") || s10.equals("DH") || s10.equals("ss") || s10.equals("tH") || s10.equals("nj") || s10.equals("nk") || s10.equals("nd") || s10.equals("nT") || s10.equals("DD") || s10.equals("dv") || s10.equals("nt") || s10.equals("nD") || s10.equals("nn") || s10.equals("nm") || s10.equals("pT") || s10.equals("pt") || s10.equals("pp") || s10.equals("bd") || s10.equals("bb") || s10.equals("mp") || s10.equals("mf") || s10.equals("mb") || s10.equals("mv") || s10.equals("mm") || s10.equals("lk") || s10.equals("lg") || s10.equals("lT") || s10.equals("lD") || s10.equals("lp") || s10.equals("lv") || s10.equals("Sk") || s10.equals("lm") || s10.equals("ll") || s10.equals("st") || s10.equals("sT") || s10.equals("nh") || s10.equals("Sp") || s10.equals("mk") || s10.equals("ng") || s10.equals("jj") || s10.equals("gg") || s10.equals("TT") || s10.equals("dd") || s10.equals("NT") || s10.equals("Nn") || s10.equals("NN") || s10.equals("Nm") || s10.equals("tt") || s10.equals("ks") || s10.equals("kk") || s10.equals("kT") || s10.equals("kt") || s10.equals("kh") || s10.equals("gh") || s10.equals("ch") || s10.equals("Ch") || s10.equals("jh") || s10.equals("Th") || s10.equals("th") || s10.equals("dh") || s10.equals("Dh") || s10.equals("sh") || s10.equals("Sh") || s10.equals("sH") || s10.equals("ph"))
                {
                    s2 = s10;
                    s = s.substring(0, s.length() - 2);
                }
            }
            if(s2.equals(""))
                if(s.length() > 0)
                {
                    s2 = s.substring(s.length() - 1);
                    s = s.substring(0, s.length() - 1);
                } else
                {
                    s2 = "";
                    s = "";
                }
            if(!s.equals("") && isalpha(s2.charAt(0)) && s.endsWith("r"))
            {
                
				s2 = "r_" + s2;
		
                if(s.length() > 0)
                    s = s.substring(0, s.length() - 1);
                else
                    s = "";
            }
            if(s3.equals(""))
            {
                if(s.equals(""))
                    s6 = BSParseSound(s2, i) + s6;
                else
                    s6 = BSParseSound(s2, i + 1) + s6;
            } else
            {
                if(s2.equals("_"))
                {
                    s6 = BSParseVowel(s3, i) + s6;
                } else
                {
                    String s5;
                    String s11;
                    if(s3.length() > 0)
                    {
                        s5 = s3.substring(0, s3.length() - 1);
                        s11 = s3.substring(s3.length() - 1);
                    } else
                    {
                        s5 = "";
                        s11 = "";
                    }
                    if(s11.equals("~") || s11.equals("o"))
                    {
                        if(s5.equals("r"))
                            s6 = BSParseSound(s2, i) + "}" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = BSParseSound(s2, i) + "{" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = BSParseSound(s2, i) + ";" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = BSParseSound(s2, i) + "y" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = BSParseSound(s2, i) + "\310" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = BSParseSound(s2, i) + "\267" + s6;
                        else
                            s6 = BSParseSound(s2, i) + s6;
                    } else
                    if(s11.equals("a"))
                    {
                        if(s5.equals("r"))
                            s6 = BSParseSound(s2, i) + "}" + "~" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = BSParseSound(s2, i) + "{" + "~" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = BSParseSound(s2, i) + ";" + "~" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = BSParseSound(s2, i) + "y" + "~" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = BSParseSound(s2, i) + "\310" + "~" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = BSParseSound(s2, i) + "\267" + "~" + s6;
                        else
                            s6 = BSParseSound(s2, i) + "~" + s6;
                    } else
                    if(s11.equals("i"))
                    {
                        if(s5.equals("R"))
                            s6 = BSParseSound(s2, i) + "|" + s6;
                        else
                        if(s5.equals("r"))
                            s6 = "[" + BSParseSound(s2, i) + "}" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = "[" + BSParseSound(s2, i) + "{" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = "[" + BSParseSound(s2, i) + ";" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = "[" + BSParseSound(s2, i) + "y" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = "[" + BSParseSound(s2, i) + "\310" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = "[" + BSParseSound(s2, i) + "\267" + s6;
                        else
                        if(s2.equals("R") && i == 1)
                            s6 = BSParseSound(s2, i) + s6;
                        else
                            s6 = "[" + BSParseSound(s2, i) + s6;
                    } else
                    if(s11.equals("I"))
                    {
                        if(s5.equals("r"))
                            s6 = BSParseSound(s2, i) + "}" + "\\" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = BSParseSound(s2, i) + "{" + "\\" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = BSParseSound(s2, i) + ";" + "\\" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = BSParseSound(s2, i) + "y" + "\\" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = BSParseSound(s2, i) + "\310" + "\\" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = BSParseSound(s2, i) + "\267" + "\\" + s6;
                        else
                            s6 = BSParseSound(s2, i) + "\\" + s6;
                    } else
                    if(s11.equals("u"))
                    {
                        if(s5.equals("r"))
                            s6 = BSParseSound(s2, i) + "}" + "#" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = BSParseSound(s2, i) + "{" + "#" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = BSParseSound(s2, i) + ";" + "#" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = BSParseSound(s2, i) + "y" + "#" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = BSParseSound(s2, i) + "\310" + "#" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = BSParseSound(s2, i) + "\267" + "#" + s6;
                        else
                            s6 = BSParseSound(s2, i) + "#" + s6;
                    } else
                    if(s11.equals("U"))
                    {
                        if(s5.equals("r"))
                            s6 = BSParseSound(s2, i) + "}" + "&" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = BSParseSound(s2, i) + "{" + "&" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = BSParseSound(s2, i) + ";" + "&" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = BSParseSound(s2, i) + "y" + "&" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = BSParseSound(s2, i) + "\310" + "&" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = BSParseSound(s2, i) + "\267" + "&" + s6;
                        else
                            s6 = BSParseSound(s2, i) + "&" + s6;
                    } else
                    if(s11.equals("e"))
                    {
                        if(s5.equals("r"))
                            s6 = "]" + BSParseSound(s2, i) + "}" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = "]" + BSParseSound(s2, i) + "{" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = "]" + BSParseSound(s2, i) + ";" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = "]" + BSParseSound(s2, i) + "y" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = "]" + BSParseSound(s2, i) + "\310" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = "]" + BSParseSound(s2, i) + "\267" + s6;
                        else
                            s6 = "]" + BSParseSound(s2, i) + s6;
                    } else
                    if(s11.equals("<"))
                    {
                        if(s5.equals("r"))
                            s6 = "^" + BSParseSound(s2, i) + "}" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = "^" + BSParseSound(s2, i) + "{" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = "^" + BSParseSound(s2, i) + ";" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = "^" + BSParseSound(s2, i) + "y" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = "^" + BSParseSound(s2, i) + "\310" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = "^" + BSParseSound(s2, i) + "\267" + s6;
                        else
                            s6 = "^" + BSParseSound(s2, i) + s6;
                    } else
                    if(s11.equals("O"))
                    {
                        if(s5.equals("r"))
                            s6 = "]" + BSParseSound(s2, i) + "}" + "~" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = "]" + BSParseSound(s2, i) + "{" + "~" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = "]" + BSParseSound(s2, i) + ";" + "~" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = "]" + BSParseSound(s2, i) + "y" + "~" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = "]" + BSParseSound(s2, i) + "\310" + "~" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = "]" + BSParseSound(s2, i) + "\267" + "~" + s6;
                        else
                            s6 = "]" + BSParseSound(s2, i) + "~" + s6;
                    } else
                    if(s11.equals(">"))
                        if(s5.equals("r"))
                            s6 = "]" + BSParseSound(s2, i) + "}" + "_" + s6;
                        else
                        if(s5.equals("y"))
                            s6 = "]" + BSParseSound(s2, i) + "{" + "_" + s6;
                        else
                        if(s5.equals("w"))
                            s6 = "]" + BSParseSound(s2, i) + ";" + "_" + s6;
                        else
                        if(s5.equals("^"))
                            s6 = "]" + BSParseSound(s2, i) + "y" + "_" + s6;
                        else
                        if(s5.equals("m"))
                            s6 = "]" + BSParseSound(s2, i) + "\310" + "_" + s6;
                        else
                        if(s5.equals("Y"))
                            s6 = "]" + BSParseSound(s2, i) + "\267" + "_" + s6;
                        else
                            s6 = "]" + BSParseSound(s2, i) + "_" + s6;
                }
                s3 = "";
            }
        }
        if(!s3.equals(""))
            s6 = BSParseVowel(s3, i);
        return s6;
    }

//////////////////////////////////////////////////////////////////////////
//
// Function:		BSParseVowel
//
// Description:		Implements Vowels
//
// INPUTS:          Phonetic English String, length of the string
// 
// RETURNS:         Parsed Bangla CodePoints (Adarsha Bangla)
//
// NOTES:			Anyone can change code points to Sutonny or AdarshaLipi etc.
// 
// MODIFICATIONS:
//
// Name                     Date        Version Comments
// Shah Ali Newaj Topu		26/08/2001    1.0     
// A.I Munna				17/06/2002    1.2     
// Ishtiaque Latif Bappa	18/06/2002    1.2 	
//////////////////////////////////////////////////////////////////////////

static String BSParseVowel(String s, int i)
{
        String s1;
		if(s.equals("~") && i == 1)
		{
            s1="A";
			return s1;
		}
        if(s.equals("a"))
            if(i == 1)
			{
                s1="A~";
				return s1;
			}
            else
			{
                s1="u~";
				return s1;
			}
        if(s.equals("i"))
		{
            s1="C";
			return s1;
		}
        if(s.equals("I"))
		{
            s1="D";
			return s1;
		}
        if(s.equals("u"))
		{
            s1="E";
			return s1;
		}
        if(s.equals("U"))
		{
            s1="F";
			return s1;
		}
        if(s.equals("e"))
		
            if(i == 1)
			{
                s1="H";
				return s1;
			}
            else
			{
				s1="\255u";
				return s1;
			}
        if(s.equals("<"))
		{
			s1="I";
			return s1;
		}
        if( s.equals("O"))
		{
            s1="J";
			return s1;
		}
        if(s.equals(">"))
		{
            s1="K";
			return s1;
		}
        else
		{
			s1="";
            return s1;
		}
}

//////////////////////////////////////////////////////////////////////////
//
// Function:		BSParseSound
//
// Description:		Process additional Phonetic Components
//
// INPUTS:          Phonetic English String, length of the string
// 
// RETURNS:         Parsed Bangla CodePoints (Adarsha Bangla)
//
// NOTES:			Anyone can change code points to Sutonny or AdarshaLipi etc.
// 
// MODIFICATIONS:
//
// Name                     Date        Version Comments
// Shah Ali Newaj Topu		26/08/2001    1.0     
// A.I Munna				17/06/2002    1.2     
//////////////////////////////////////////////////////////////////////////

static String BSParseSound(String s, int i)
    {
        String s1;
        String s2;
		s1="";
		s2="";
        if(s.length() > 2 && s.startsWith("r_"))
        {
            s = s.substring(2);
            s2 = "r_";
        }

        if(s.equals("k"))
            s1 = "L";
        
        if(s.equals("kh"))
            s1 = "M";
        
        if(s.equals("kl"))
            s1 = "L\323";
        
        if(s.equals("g"))
            s1 = "N";
        
        if(s.equals("gh"))
            s1 = "O";
        
        if(s.equals("gl"))
            s1 = "N.";
        
        if(s.equals("ch"))
            s1 = "Q";
        
        if(s.equals("s") || !s.equals("sh"))
            s1 = "ñ";
        
        if(s.equals("j"))
            s1 = "S";
        
        if(s.equals("jh"))
            s1 = "T";
        
        if(s.equals("T"))
            s1 = "V";
        
        if(s.equals("Th"))
            s1 = "W";
        
        if(s.equals("D"))
            s1 = "X";
        
        if(s.equals("Dh"))
            s1 = "Y";
        
        if(s.equals("N"))
            s1 = "Z";
        
        if(s.equals("t"))
            s1 = "a";
        
        if(s.equals("th"))
            s1 = "b";
        
        if(s.equals("d"))
            s1 = "c";
        
        if(s.equals("dh"))
            s1 = "d";
        
        if(s.equals("n"))
            s1 = "e";
        
        if(s.equals("p"))
            s1 = "f";
        
        if(s.equals("f") || s.equals("ph"))
            s1 = "g";
        
        if(s.equals("fl") || s.equals("phl"))
            s1 = "g\323";
        
        if(s.equals("b"))
            s1 = "h";
        
        if(s.equals("v"))
            s1 = "i";
        
        if(s.equals("m"))
            s1 = "j";
        
        if(s.equals("J"))
            s1 = "k";
        
        if(s.equals("r"))
            s1 = "l";
        
        if(s.equals("l"))
            s1 = "m";
        
        if(s.equals("Sh"))
            s1 = "n";
        
        if(s.equals("sH"))
            s1 = "o";
        
        if(s.equals("sh") || s.equals("S"))
            s1 = "p";
        
        if(s.equals("h"))
            s1 = "q";
        
        if(s.equals("R"))
        {
            if(i == 1)
                s1 = "G";
            
                s1 = "s";
        } 
        if(s.equals("DH"))
            s1 = "t";
        
        if(s.equals("A") || s.equals("y"))
            s1 = "u";
        
        if(s.equals("tH"))
            s1 = "v";
        
        if(s.equals("<ng>"))
            s1 = "w";
        
        if(s.equals("ng"))
            s1 = "/";
        
        if(s.equals(" "))
            s1 = " ";
        
        if(s.equals("|"))
            s1 = "z";
        
        if(s.equals(":"))
            s1 = "x";
        
        if(s.equals("kk"))
            s1 = "\351";
        
        if(s.equals("kT"))
            s1 = "\342";
        
        if(s.equals("kt"))
            s1 = "(@";
        
        if(s.equals("ks") || s.equals("x") || s.equals("ksh"))
            s1 = "\344";
        
        if(s.equals("khkh") || s.equals("kkh"))
            s1 = "r";
        
        if(s.equals("gdh"))
            s1 = "N>";
        
        if(s.equals("mk"))
            s1 = "UL";
        
        if(s.equals("nk"))
            s1 = "\352";
        
        if(s.equals("chch") || s.equals("cch"))
            s1 = "\265Q";
        
        if(s.equals("ss") || s.equals("chs") || s.equals("cCh"))
            s1 = "\265R";
        
        if(s.equals("jj"))
            s1 = "\357";
        
        if(s.equals("jjh"))
            s1 = "S>";
        
        if(s.equals("gg"))
            s1 = "-";
        
        if(s.equals("TT"))
            s1 = "\373";
        
        if(s.equals("DD"))
            s1 = "XX";
        
        if(s.equals("NT"))
            s1 = "=V";
        
        if(s.equals("Nth"))
            s1 = "=W";
        
        if(s.equals("NDh"))
            s1 = "=Y";
        
        if(s.equals("Nn") || s.equals("NN"))
            s1 = "=\310";
        
        if(s.equals("Nm"))
            s1 = "Z\310";
        
        if(s.equals("tt"))
            s1 = "(";
        
        if(s.equals("dd"))
            s1 = "c`";
        
        if(s.equals("ddh") || s.equals("dhdh"))
            s1 = "c>";
        
        if(s.equals("dv") || s.equals("dbh"))
            s1 = "\341";
        
        if(s.equals("nT"))
            s1 = "=V";
        
        if(s.equals("nTh"))
            s1 = "=W";
        
        if(s.equals("nD"))
            s1 = "=X";
        
        if(s.equals("nDh"))
            s1 = "=Y";
        
        if(s.equals("ndh"))
            s1 = "e>";
        
        if(s.equals("ngh"))
            s1 = "\264O";
        
        if(s.equals("nt"))
            s1 = "=a";
        
        if(s.equals("nth"))
            s1 = "=<";
        
        if(s.equals("nd"))
            s1 = "=c";
        
        if(s.equals("nn"))
            s1 = "eP";
        
        if(s.equals("nm"))
            s1 = "=j";
        
        if(s.equals("pT"))
            s1 = "%V";
        
        if(s.equals("pt"))
            s1 = "%a";
        
        if(s.equals("pp"))
            s1 = "%f";
        
        if(s.equals("psh"))
            s1 = "%p";
        
        if(s.equals("bd"))
            s1 = "h`";
        
        if(s.equals("bdh"))
            s1 = "h>";
        
        if(s.equals("bb"))
            s1 = "h;";
        
        if(s.equals("mp"))
            s1 = "Uf";
        
        if(s.equals("mf") || s.equals("mph"))
            s1 = "Ug";
        
        if(s.equals("mb"))
            s1 = "Uh";
        
        if(s.equals("mv"))
            s1 = "Ui";
        
        if(s.equals("mm"))
            s1 = "Uj";
        
        if(s.equals("lk"))
            s1 = "'L";
        
        if(s.equals("lg"))
            s1 = "'N";
        
        if(s.equals("lT"))
            s1 = "'V";
        
        if(s.equals("lD"))
            s1 = "'X";
        
        if(s.equals("lp"))
            s1 = "'f";
        
        if(s.equals("lv") || s.equals("lbh"))
            s1 = "'i";
        
        if(s.equals("lm"))
            s1 = "'j";
        
        if(s.equals("ll"))
            s1 = "m.";
        
        if(s.equals("Shch"))
            s1 = "\325Q";
        
        if(s.equals("ShCh"))
            s1 = "\325R";
        
        if(s.equals("sHk"))
            s1 = "*L";
        
        if(s.equals("sHT"))
            s1 = "*V";
        
        if(s.equals("sHTh"))
            s1 = "*W";
        
        if(s.equals("sHp"))
            s1 = "*f";
        
        if(s.equals("sHf") || s.equals("sHph"))
            s1 = "*g";
        
        if(s.equals("sHm"))
            s1 = "*j";
        
        if(s.equals("shk") || s.equals("Sk"))
            s1 = "+L";
        
        if(s.equals("shkh") || s.equals("Skh"))
            s1 = "+M";
        
        if(s.equals("sT"))
            s1 = "+V";
        
        if(s.equals("st"))
            s1 = "+a";
        
        if(s.equals("shp") || s.equals("Sp"))
            s1 = "+f";
        
        if(s.equals("sth"))
            s1 = "+<";
        
        if(s.equals("shf") || s.equals("shph"))
            s1 = "+g";
        
        if(s.equals("nh"))
            s1 = "q@";
        
        if(s.equals("nj"))
            s1 = ":";
        
        if(s.equals("nch"))
            s1 = "\351";
        
        if(s.equals("Rh"))
            s1 = "t";
        
        if(s.equals("Y"))
            s1 = "U";
        
        if(s.equals("M"))
            s1 = "P";
        
        if(s.equals("_"))
            s1 = "";
        
        if(s.equals("mn"))
            s1 = "jP";
        
        if(s.equals("tn"))
            s1 = "aP";
        
        if(s.equals("hN"))
            s1 = "qP";
        
        if(s.equals("sHY") || s.equals("sHn"))
            s1 = "o\267";
        
        if(s.equals("gn") || s.equals("gN"))
            s1 = "NP";
        
        if(s.equals("bj"))
            s1 = "\352";
        
        if(s.equals("Shn"))
            s1 = "nP";
        
        if(s.equals("Sn"))
            s1 = "pP";
        
        if(s.equals("tth"))
            s1 = "\242";
        
        if(s.equals("pn"))
            s1 = "fP";
        
        if(s.equals("pl"))
            s1 = "f.";
        
        if(s.equals("bl"))
            s1 = "h.";
        
        if(s.equals("\n") || s.equals("\"") || s.equals("!") || s.equals("1") || s.equals("2") || s.equals("3") || s.equals("4") || s.equals("5") || s.equals("6") || s.equals("7") || s.equals("8") || s.equals("9") || s.equals("0") || s.equals("?") || s.equals(","))
        {
            s1 = s;
            s2 = "";
        }
        if(s2.equals("r_"))
		{
			String s3;
			s3=s1+"$";
            return s3;
		}
        else
            return s1;
    }

//////////////////////////////////////////////////////////////////////////
//
// Function:		Replace
//
// Description:		Standard String Replace function
//
// INPUTS:          Main String, From Char ,To Char 
// 
// RETURNS:         Result String
//
// NOTES:			
// 
// MODIFICATIONS:
//
// Name                     Date        Version Comments
// Shah Ali Newaj Topu		26/08/2001    1.0     

//////////////////////////////////////////////////////////////////////////

String Replace(String s, char *s1, char * s2)
{
	s.Replace(s1,s2);
    return s;
}

