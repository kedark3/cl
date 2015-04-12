import java.rmi.*;
import java.rmi.server.*;

public class BankImpl extends UnicastRemoteObject implements BankIntf{
	public BankImpl() throws RemoteException{
	}
	public int deposit(int amount,int balance) throws RemoteException
	{
		return balance+amount;
	}
	public int withdraw(int amount,int balance) throws RemoteException
	{
		return balance-amount;
	}
}
