import java.rmi.Naming;
import java.util.Scanner;

public class SumClient {
	public static void main(String args[]){
		try{
			Scanner in= new Scanner(System.in);
			String sumServerURL="rmi://"+args[0]+"/SUM-SERVER";
			SumServerIntf  sumServerIntf=(SumServerIntf)Naming.lookup(sumServerURL);
			System.out.println("The first number is: " + args[1]);
			int m = Integer.valueOf(args[1]);
			System.out.println("The second number is: " + args[2]);
			int n = Integer.valueOf(args[2]);
			System.out.println("\n1:sum\n2:Sub\n3:Mul\n4:Div\n5:Exp" );
			int ch=in.nextInt();
			switch(ch)
			{
				case 1:
				System.out.println("The sum is: " + sumServerIntf.sum(m,n));
				break;
				
				case 2:
				System.out.println("The sub is: " + sumServerIntf.sub(m,n));
				break;
				
				case 3:
				System.out.println("The sub is: " + sumServerIntf.mul(m,n));
				break;
				
				case 4:
				System.out.println("The sub is: " + sumServerIntf.div(m,n));
				break;
				
				case 5:
				System.out.println("The sub is: " + sumServerIntf.exp(m,n));
				break;
			}	
		}
		catch(Exception e){
			System.out.println("Exception: " + e);
		}
	}
}
