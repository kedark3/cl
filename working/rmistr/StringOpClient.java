import java.rmi.Naming;
import java.util.Scanner;

public class StringOpClient{
	public static void main(String [] args){
		try{
			String StringOpURL="rmi://"+args[0]+"/StrOp";
			StringOpIntf strinf=(StringOpIntf)Naming.lookup(StringOpURL);
			Scanner in= new Scanner(System.in);
			System.out.println("\nEnter String 1:");
			String s1=in.nextLine();
			System.out.println("\nEnter String 2:");
			String s2=in.nextLine();
			System.out.println("Concatenation:"+strinf.conc(s1,s2));
			System.out.println("Reverse of s1:"+strinf.reverse(s1));
			System.out.println("Reverse of s2:"+strinf.reverse(s2));
			System.out.println("Length of s1:"+strinf.strLen(s1));
			System.out.println("Length of s2:"+strinf.strLen(s2));
		}
		catch(Exception e){
			System.out.println("Exception:"+e);
		}
	}
}
