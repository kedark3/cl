import java.rmi.*;

public class BankServer{
	public static void main(String args[])
	{
		try{
			BankImpl b= new BankImpl();
			Naming.rebind("Bank",b);
			
		}
			catch (Exception e){
			System.out.println("Exception is :------->\n\n"+e);
		}
	}
}
