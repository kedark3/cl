import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			ServerSocket server_sock = new ServerSocket(9999);
			Socket sock = server_sock.accept();
			BufferedReader br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			String temp = br.readLine();
			System.out.print("Message from Client: " +temp);
			PrintStream ps = new PrintStream(sock.getOutputStream());
			ps.println("Echo frm Server: "+temp);
			}
			catch(Exception ex){}
			}

	}
