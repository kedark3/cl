import java.rmi.*;

public interface StringOpIntf extends Remote{
	String conc(String s1, String s2) throws RemoteException;
	String reverse(String s) throws RemoteException;
	String subStr(String s1,String s2) throws RemoteException;
	int strLen(String s)throws RemoteException;
}

