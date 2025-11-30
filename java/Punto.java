
public class Punto {
	
	private static int alloc = 0;
	
	private final int x;
	private final int y;
	
	public Punto() {
		this(0, 0);
	}
	
	public Punto(int x , int y) {
		
		this.x = x;
		this.y = y;
		this.alloc++;
	}
	
	public int getX() {
		return this.x;
	}
	
	public int getY() {
		return this.y;
	}
	
	public String toString() {
		return x + ", " + y;
	}
	
	public static int getAlloc() {
		return alloc;
	}
}
