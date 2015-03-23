import java.rmi.*;

public class SumServer {
	public static void main(String args[]){
		try{
			SumServerImpl sumServerImpl = new SumServerImpl();
			Naming.rebind("SUM-SERVER", sumServerImpl);
		}
		catch(Exception e){
			System.out.println("Exception is:"+e);
		}
	}
}
