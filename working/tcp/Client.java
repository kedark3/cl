import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;


public class Server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Socket client_Sock = new Socket("localhost",9999);
			PrintStream ps = new PrintStream(client_Sock.getOutputStream());
			System.out.print("Enter the message: ");
			BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
			String temp =br.readLine();
			ps.println(temp);
			BufferedReader br1 =new BufferedReader(new
			InputStreamReader(client_Sock.getInputStream()));
			String temp2 = br1.readLine();
			System.out.print(temp2);
			}
			catch(Exception ex){}
			}

	}

