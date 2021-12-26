import java.util.Comparator;
import edu.princeton.cs.algs4.StdDraw;

public class Point implements Comparable<Point> 
{
    private final int x;
    private final int y;

	public Point(int x, int y)                         // constructs the point (x, y)
	{
		this.x = x;
		this.y = y;
	}

	public   void draw()                               // draws this point
	{
        StdDraw.point(x, y);
	}

	public   void drawTo(Point that)                   // draws the line segment from this point to that point
	{
        StdDraw.line(this.x, this.y, that.x, that.y);
	}

	public String toString()                           // string representation
	{
        return "(" + x + ", " + y + ")";
	}

	public int compareTo(Point that)     // compare two points by y-coordinates, breaking ties by x-coordinates
	{
        if (this.y < that.y)
        	return -1;
        if (this.y > that.y)
        	return +1;
        if (this.x < that.x)
        	return -1;
        if (this.x > that.x)
        	return +1;
        
        return 0;
	}
	public double slopeTo(Point that)       // the slope between this point and that point
	{
		if (this.compareTo(that) == 0)
		    return Double.NEGATIVE_INFINITY;

		/* Horizontal line segment */
		if (that.y == this.y)
		    return 0.0;

		/* Vertical line segment */
		if (that.x == this.x)
		    return Double.POSITIVE_INFINITY;

		double diffX = that.x - this.x;
		double diffY = that.y - this.y;

		return diffY / diffX;
	}

	public Comparator<Point> slopeOrder()              // compare two points by slopes they make with this point
	{
		return new Comparator<Point>() {
		    @Override
		    public int compare(Point a, Point b) {
		        double slopeDiff = slopeTo(a) - slopeTo(b);
		        if (slopeDiff > 0) return 1;
		        else if (slopeDiff < 0) return -1;
		        else return 0;
		    }
		};
	}
}