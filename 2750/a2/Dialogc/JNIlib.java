import javax.swing.*;
import java.io.File;

public class JNIlib{
	
	static {System.load(new File (".").getAbsolutePath() + "/libpm.so");}
	
	public native static int PM_create(int size);
	
	public native static int PM_destroy();
	
	public native static int PM_parseFrom(String file, char comment);
	
	public native static int PM_manage(String name, int type, int required);
	
	public native static int hasValue(String name);
	
	public native static String getValue(String name, int index);
	
	public native static int getListSize(int index);
}
