package pl.droidsonroids.ndkdemo;

public class Demo {
	static {
		System.loadLibrary("demo");
	}
	public native String getHelloWorld();
}
