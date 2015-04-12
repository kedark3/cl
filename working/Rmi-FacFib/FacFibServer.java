import java.rmi.*;

public class FacFibServer{
	public static void main(String [] args){
		try{
			FacFibImpl facFibImpl= new FacFibImpl();
			Naming.rebind("Fib-Fac",facFibImpl);
			
		}
		catch (Exception e){
			System.out.println("Exception is :------->\n\n"+e);
		}
	}
}
