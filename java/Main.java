
public class Main <T extends Comparable<T>>{
	
	
	// T deve essere una classe (Integer...)
	public String reverse(String s) {
		
		String s2;
		int x = s.length() - 1;
		char[] c = new char[s.length()];
		
		for (int i = 0; i < s.length(); i++) {
			
			c[i] = s.charAt(x--);
		}
		
		s2 = new String(c);
		return s2;
	}
	
		
public static void main(String[] args) {
	
	Main m1 = new Main();
	String s1 = "oioioi";
	String s2 = new String(m1.reverse(s1));
	System.out.println(s2);
}
	
}
