package pl.droidsonroids.ndkdemo;

public class Foo {
	private final Object mGuardian = new Object() {
		@Override
		protected void finalize() throws Throwable {
			try {
				release();
			} finally {
				super.finalize();
			}
		}
	};

	private native void release();

	@Override
	protected void finalize() throws Throwable {
		try {
			release();
		} finally {
			super.finalize();
		}
	}

	static class Bar extends Foo {

		@Override
		protected void finalize() throws Throwable {

		}
	}
}
