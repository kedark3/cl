import java.util.Scanner;
import java.rmi.Naming;

public class FacFibClient
{
	public static void main(String args[])
	{
		try{
			int m;

			String s;
			Scanner in= new Scanner(System.in);
			System.out.println("Enter Server IP:\t");
			s=in.nextLine();
			String FacFibServerURL="rmi://"+s+"/Fib-Fac";
			FacFibIntf facFibIntf= (FacFibIntf)Naming.lookup(FacFibServerURL);
			System.out.println("Enter number:\t");
			m=in.nextInt();
			System.out.println("Factorial is:\t"+ facFibIntf.factorial(m));
			int[] arr=facFibIntf.fibonacci(m);
			System.out.println("Fibonacci is:\t"+ arr);
		}
		catch (Exception e){
			System.out.println("Exception"+e);
		}
	}

}
