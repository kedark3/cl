import java.rmi.*;

public interface BankIntf extends Remote{
	int deposit(int amount,int balance) throws RemoteException;
	int withdraw(int amount,int balance) throws RemoteException;
}
