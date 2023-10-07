
class String:public CString
{
	public:
		//int equals(char *);
		int equals(char *Str)
		{
			if(*this==Str)
				return(1);
			else
				return(0);
			//return(Compare(Str)==1?1:0);
		}

		void operator =(CString x)
		{
			char *Buffer;
			//Buffer=x.GetBuffer(GetLength());
			//*this=Buffer;
			Buffer=(char *)x.GetBuffer(x.GetLength());
			Empty();
			if(Buffer[0]!=0)
				Insert(0,x.GetBuffer(x.GetLength()));
		}
		String operator +(String x)
		{
			String s;
			s.Insert(0,GetBuffer(x.GetLength()));
			s.Insert(s.GetLength(),x.GetBuffer(x.GetLength()));
			return(s);
		}

		int length()
		{
			return(GetLength());
		}
		int startsWith(char *x)
		{
			char *Buffer2;
			int i=0;
			Buffer2=GetBuffer(GetLength());
			for(int i=0; i < strlen(x); i++)
				if(x[i] != Buffer2[i])
					break;
			if(i == strlen(x))
				return(1);
			return(0);
		}
		String substring(int Start)
		{
			String x;
			char *Buffer2;
			Buffer2=GetBuffer(GetLength());
			for(int i=Start;i<GetLength();i++)
			{
				x.Insert(i,Buffer2[i]);
			}
			return(x);
		}
		String substring(int Start,int End)
		{
			String x;
			char *Buffer2;
			Buffer2=GetBuffer(GetLength());
			for(int i=Start;i<End;i++)
			{
				x.Insert(i,Buffer2[i]);
			}
			return(x);
		}
		int endsWith(char *x)
		{
			char *Buffer2;
			int j=0;
			Buffer2=GetBuffer(GetLength());
			for(int i=strlen(Buffer2)-1,j=strlen(x)-1;j>=0;i--,j--)
			{
				if(x[j]!=Buffer2[i])
					break;
			}
			if(j==-1)
				return(1);
			return(0);
		}
		int indexOf(char *Str)
		{
			return(Find(Str));
		}
		char charAt(int Pos)
		{
			//return(GetAt(Pos));
			char *Buffer2;
			Buffer2=GetBuffer(GetLength());
			return(Buffer2[Pos]);
		}
};
