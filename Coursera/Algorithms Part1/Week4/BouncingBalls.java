public class BouncingBalls
{
	public static void main(String[] args) 
	{
		int n = Integer.parseInt(args[0]);
		Ball[] balls = new Ball[N];
		for (int i=0;i<n;i++)
			balls[i] = new Ball();

		while(true)
		{
			StdDraw.clear();
			for(int i=0;i<n;i++)
			{
				balls[i].move(0.5);
				balls[i].draw();
			}
			StdDraw.show(50);
		}
	}
}