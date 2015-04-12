import java.rmi.*;

public interface SumServerIntf extends Remote{
	int sum(int m, int n) throws RemoteException;
}
