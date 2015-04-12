import java.rmi.*;
import java.rmi.server.*;

public class StringOpImpl extends UnicastRemoteObject implements StringOpIntf{
	public StringOpImpl() throws RemoteException{
	}
	
	public String conc(String s1,String s2) throws RemoteException{
		String s;
		s=s1+s2;
		return s;
	}
	public String reverse(String s)
	{
		int i;
		String rev="";
		for (  i = s.length() - 1 ; i >= 0 ; i-- )
	        	rev = rev + s.charAt(i);
		return rev;
	}
	public String subStr(String s1,String s2) throws RemoteException
	{
		return s1;
	}
	public int strLen(String s)throws RemoteException{
		return s.length();
	}
}
