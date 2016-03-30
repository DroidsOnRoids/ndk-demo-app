#butterknife 7.0.1
-keep class butterknife.** { *; }
-dontwarn butterknife.internal.**
-keep class **$$ViewBinder { *; }

-keep class pl.droidsonroids.ndkdemo.Demo{ int getHash(); }
-keep class pl.droidsonroids.ndkdemo.Demo{ native <methods>; }