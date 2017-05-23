public class FractionAdditionAndSubtraction{
	
	private static class Fraction
	{
		private int upper,lower;
		public Fraction(int upper,int lower){
			this.upper = upper;
			this.lower = lower;
		}
		public Fraction add(Fraction rhs){
			int upper = this.upper*rhs.lower+this.lower*rhs.upper;
			int lower = this.lower*rhs.lower;
			if (upper==0){
				return new Fraction(0,1);
			}
			int k=gcd(Math.abs(upper),lower);
			upper/=k;
			lower/=k;
			return new Fraction(upper,lower);
		}
	}

	private static int gcd(int a,int b){
		if (a<b){
			return gcd(b,a);
		}
		if (a%b==0){
			return b;
		}else{
			return gcd(b,a%b);
		}
	}
	
	public String fractionAddition(String exp) {
		int start=0;
		int end=1;
		Fraction sum=new Fraction(0,1);
		while (start<exp.length()){
			end=start+1;
			while (end<exp.length() && exp.charAt(end)!='-' && exp.charAt(end)!='+'){
				end++;
			}
			String sub=exp.substring(start, end);
			int slashIndex=sub.indexOf("/");
			int upper=Integer.valueOf(sub.substring(0, slashIndex));
			int lower=Integer.valueOf(sub.substring(slashIndex+1));
			sum=sum.add(new Fraction(upper,lower));
			start=end;
		}
		String ans=String.valueOf(sum.upper)+"/"+String.valueOf(sum.lower);
		return ans;
	}
}
