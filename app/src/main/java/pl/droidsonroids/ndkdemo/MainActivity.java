package pl.droidsonroids.ndkdemo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import butterknife.Bind;
import butterknife.ButterKnife;

public class MainActivity extends Activity {

	@Bind(R.id.textview_hello)
	TextView mTextViewHello;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		ButterKnife.bind(this);
		final Demo demo = new Demo();
		mTextViewHello.setText(demo.getHelloWorld());
	}

}
