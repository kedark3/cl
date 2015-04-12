import java.rmi.*;

public class StringOpServer{

	public static void main(String [] args)
	{
		try{
			StringOpImpl s=new StringOpImpl();
			Naming.rebind("StrOp",s);
		}
		catch(Exception e)
		{
			System.out.println("Exception is:"+e);
		}
	}
}
