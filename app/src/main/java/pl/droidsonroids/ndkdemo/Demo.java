package pl.droidsonroids.ndkdemo;

public class Demo {
	static {
		System.loadLibrary("demo");
	}

	private long mNativeDemo;

	public native String getHelloWorld();

	private native long init();

	private native void release(long ptr);

	public Demo() {
		mNativeDemo = init();
	}

	public void release() {
		release(mNativeDemo);
		mNativeDemo = 0;
	}
}
