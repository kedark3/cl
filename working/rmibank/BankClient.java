import java.util.Scanner;
import java.rmi.Naming;

public class BankClient
{
	public static void main(String args[])
	{
		try{
			int balance,amount;
			String s;
			Scanner in=new Scanner(System.in);
			System.out.println("Enter Server IP:\t");
			s=in.nextLine();
			String BankServerURL="rmi://"+s+"/Bank";
			BankIntf b= (BankIntf)Naming.lookup(BankServerURL);
			System.out.println("Enter balance:\t");
			balance=in.nextInt();
			
			int userChoice;
			boolean quit = false;
			do {
				System.out.println("1. Deposit money");
				System.out.println("2. Withdraw money");
				System.out.println("3. Check balance");
				System.out.print("Your choice, 0 to quit: ");
				userChoice = in.nextInt();
				switch (userChoice) {
				case 1:
				        System.out.println("Enter amount:\t");
					amount=in.nextInt();
			
				        balance=b.deposit(amount,balance);// deposit money
				        System.out.println("New Balance :"+balance);
				        break;
				case 2:
					System.out.println("Enter amount:\t");
					amount=in.nextInt();
				        balance=b.withdraw(amount,balance);// withdraw money
				        System.out.println("New Balance :"+balance);
				        break;
				case 3:
					System.out.println("Balance :"+balance);// check balance
				        break;
				case 0:
				        quit = true;
				        break;
				default:
				        System.out.println("Wrong choice.");
				        break;
				}
				System.out.println();
			   } while (!quit);	
		}
		catch (Exception e){
			System.out.println("Exception"+e);
		}
	}

}
