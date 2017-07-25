struct vir
{
	double re,im;
	inline vir(double _re = 0.,double _im = 0.) : re(_re),im(_im){}
	inline vir operator *(const vir &r)
	{ return vir(re*r.re-im*r.im,re*r.im+im*r.re); }
	inline vir operator +(const vir &r)
	{ return vir(re+r.re,im+r.im); }
	inline vir operator -(const vir &r)
	{ return vir(re-r.re,im-r.im); }
	inline vir operator /(double r) { return vir(re/r,im/r); }
}pa[maxn],pb[maxn];

inline void fft(vir *a,int loglen,int len,int on)
{
	for (int i = 0,j,t,p;i < len;++i)
	{
		for (p = j = 0,t = i;j < loglen;++j,t >>= 1)
			p <<= 1,p |= (t&1);
		if (p > i) swap(a[p],a[i]);
	}
	for (int m = 2,s = 1;s <= loglen;++s,m <<= 1)
	{
		vir w = (vir){cos(2*pi*on/m),sin(2*pi*on/m)};
		for (int i = 0;i < len;i += m)
		{
			vir wn = (vir) {1,0};
			for (int j = 0;j < (m>>1);++j,wn = wn*w)
			{
				vir u = a[i+j],v = wn*a[i+j+(m>>1)];
				a[i+j] = u+v; a[i+j+(m>>1)] = u-v;
			}
		}
	}
	if (on == -1) for (int i = 0;i < len;++i) a[i] = a[i]/len;
}

inline void work()
{
	int loglen = 0,len;
	while ((1<<loglen) < l) ++loglen; len = 1 << loglen;
	fft(pa,loglen,len,1); fft(pb,loglen,len,1);
	for (int i = 0;i < len;++i) pa[i] = pa[i]*pb[i];
	fft(pa,loglen,len,-1);
}
