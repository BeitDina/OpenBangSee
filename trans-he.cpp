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
// INPUTS:          Phonetic Romanian String (Diacritics)
// 
// RETURNS:         Parsed Hebrew CodePoints (Niqud)
//
// NOTES:			Anyone can change code points to Hebrew Transliteration etc.
// 
// MODIFICATIONS:
//
// Name                     Date        Version Comments
// FlorinCB aka github.com/orynider	06/10/2023    1.0      
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
        //s = Replace(s, "kh", "ch");
        boolean flag = false;
        boolean flag1 = false;
        int i = 0;
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

            if(s4.equals("\n") || s4.equals("\"") || s4.equals("!") || s4.equals("1") || s4.equals("2") || s4.equals("3") || s4.equals("4") || s4.equals("5") || s4.equals("6") || s4.equals("7") || s4.equals("8") || s4.equals("9") || s4.equals("0") || s4.equals("?") || s4.equals(","))
            {
                i = 0;
                s1 = s1 + BSParseSyllable(s2, i);
                s2 = "";
            } else
            if(!s4.equals(""))
            {
                i++;
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
        s1 = Replace(s1, "ă", "ee");
        s1 = Replace(s1, "ş", "sh");
        s1 = Replace(s1, "ţ", "tz");
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
        if(!s7.equals(""))
        {
            s3 = s7;
            s = s.substring(0, s.length() - 1);
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
	
//////////////////////////////////////////////////////////////////////////

static String BSParseVowel(String s, int i)
{
        String s1;
        if(s.equals("e"))	
            if(i == 1)
			{
                s1="א";
				return s1;
			}
            else
			{
                s1="א";
				return s1;
			}
		if(s.equals("ב") && i == 1)
		{
            s1="b";
			return s1;
		}
		if(s.equals("ג") && i == 1)
		{
            s1="g";
			return s1;
		}
		if(s.equals("ד") && i == 1)
		{
            s1="d";
			return s1;
		}
		if(s.equals("ה") && i == 1)
		{
            s1="h";
			return s1;
		}
		if(s.equals("ע") && i == 1)
		{
            s1="a";
			return s1;
		}
        if(s.equals("a"))
            if(i == 1)
			{
                s1="ע";
				return s1;
			}
            else
			{
                s1="ע";
				return s1;
			}
        if(s.equals("i"))
		{
            s1="י";
			return s1;
		}
        if(s.equals("ו"))
		{
            s1="u";
			return s1;
		}
        if(s.equals("u"))
		{
            s1="ו";
			return s1;
		}

        if(s.equals("ת"))
		{
            s1="t";
			return s1;
		}
        else
		{
			s1="?";
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
 
//////////////////////////////////////////////////////////////////////////

static String BSParseSound(String s, int i)
    {
        String s1;
        String s2;
        String s3;
		s1="";
		s2="";
		s3="";
        if(s.length() > 2 && s.startsWith("r_"))
        {
            s = s.substring(2);
            s2 = "r_";
        }

        if(s.equals("ל"))
            s1 = "L";  
        if(s.equals("מ"))
            s1 = "M";        
        if(s.equals("ק"))
            s1 = "Q";
        if(s.equals("q"))
            s1 = "ק";   
        if(s.equals("Ch") || s.equals("s"))
            s1 = "ח";
        if(s.equals("j"))
            s1 = "ג";       
        if(s.equals("th"))
            s1 = "ט"; 
        if(s.equals("ז"))
            s1 = "z";
         if(s.equals("z"))
            s1 = "ז";     
        if(s.equals("J"))
            s1 = "k";
        if(s.equals("r"))
            s1 = "l";
        if(s.equals("l"))
            s1 = "m";
        if(s.equals("Sh"))
            s1 = "ש";
        if(s.equals("ש"))
            s1 = "ş";  
        if(s.equals("sh") || s.equals("S"))
            s1 = "ש";             
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
  

//////////////////////////////////////////////////////////////////////////

String Replace(String s, char *s1, char * s2)
{
	s.Replace(s1, s2);
    return s;
}

