import java.rmi.Naming;


public class SumClient {
	public static void main(String args[]){
		try{
			String sumServerURL="rmi://"+args[0]+"/SUM-SERVER";
			SumServerIntf  sumServerIntf=(SumServerIntf)Naming.lookup(sumServerURL);
			System.out.println("The first number is: " + args[1]);
			int m = Integer.valueOf(args[1]);
			System.out.println("The second number is: " + args[2]);
			int n = Integer.valueOf(args[2]);
			System.out.println("The sum is: " + sumServerIntf.sum(m, n));
		}
		catch(Exception e){
			System.out.println("Exception: " + e);
		}
	}
}
