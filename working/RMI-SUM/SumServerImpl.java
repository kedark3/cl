import java.rmi.*;
import java.rmi.server.*;

public class SumServerImpl extends UnicastRemoteObject implements SumServerIntf {
	public SumServerImpl() throws RemoteException {
	
	}
	public int sum(int m,int n) throws RemoteException {
		return m+n;
	}

}
