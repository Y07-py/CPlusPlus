//#define NDEBUG

#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx")  //Enable AVX
#ifndef _MSC_VER
#include <x86intrin.h> //AVX/SSE Extensions
#endif
#ifdef _MSC_VER
#pragma warning(1:4456)
#endif
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define ALL(a) (a).begin(),(a).end()
#define MEM2LOC(type,name) type name=(this->name);
#define MEM2LOC_V(type,name) type name=((this->name).data());
#define LOC2MEM(name) (this->name)=(name);
#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<iomanip>
#include<math.h>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<memory>
#include<cassert>
#include<functional>
#include<chrono>
#include<bitset>
using namespace std;
using namespace chrono;
namespace ValLib {
	constexpr double DIST_INF=1e100;
	constexpr int DX4[]={0,-1,0,1};
	constexpr int DY4[]={-1,0,1,0};
	constexpr int DX8[]={0,-1,-1,-1,0,1,1,1};
	constexpr int DY8[]={-1,-1,0,1,1,1,0,-1};
	constexpr int DX5[]={DX4[0],DX4[1],DX4[2],DX4[3],0};
	constexpr int DY5[]={DY4[0],DY4[1],DY4[2],DY4[3],0};
	constexpr int DX9[]={DX8[0],DX8[1],DX8[2],DX8[3],DX8[4],DX8[5],DX8[6],DX8[7],0};
	constexpr int DY9[]={DY8[0],DY8[1],DY8[2],DY8[3],DY8[4],DY8[5],DY8[6],DY8[7],0};
	typedef unsigned int uint;
	typedef long long ll;
	typedef unsigned long long ull;
	constexpr ll V_MOD = 998244353ll;
	constexpr int V_INT_MAX = 2147483647;
	constexpr ll V_LL_MAX = 9223372036854775807ll;
	constexpr ull V_ULL_MAX = 18446744073709551615ull;
	template<class T,size_t A>using array1=array<T,A>;
	template<class T,size_t A,size_t B>using array2=array<array<T,B>,A>;
	template<class T,size_t A,size_t B,size_t C>using array3=array<array2<T,B,C>,A>;
	template<class T,size_t A,size_t B,size_t C,size_t D>using array4=array<array3<T,B,C,D>,A>;
	template<class T,size_t A,size_t B,size_t C,size_t D,size_t E>using array5=array<array4<T,B,C,D,E>,A>;
	template<class T>using vector1=vector<T>;
	template<class T>using vector2=vector<vector<T>>;
	template<class T>using vector3=vector<vector2<T>>;
	template<class T>using vector4=vector<vector3<T>>;
	template<class T>using vector5=vector<vector4<T>>;
	template<typename Key,typename Value>using umap=std::unordered_map<Key,Value>;
	template<typename T>using uset=std::unordered_set<T>;
	template<typename T>using sptr=typename std::shared_ptr<T>;
	template<class _Iter>using iter_cat_type=typename std::iterator_traits<_Iter>::iterator_category;
	template<class _Ty,class=void>constexpr bool _is_iterator=false;
	template<class _Ty>constexpr bool _is_iterator<_Ty,std::void_t<iter_cat_type<_Ty>>> = true;
	template<typename T>void fill(vector<T>&a,const T&v){std::fill(ALL(a),v);}
	template<typename T>void fill(vector<vector<T>>&a,const T&v){for(vector<T>&t:a)std::fill(ALL(t),v);}
	template<typename T>void resize(vector<T>&a,int sz1){a.resize(sz1);}
	template<typename T>void resize(vector<T>&a,int sz1,const T&v){a.resize(sz1,v);}
	template<typename T>void resize(vector<vector<T>>&a,int sz1,int sz2){a.resize(sz1);for(vector<T>&t:a)t.resize(sz2);}
	template<typename T>void resize(vector<vector<T>>&a,int sz1,int sz2,const T&v){a.resize(sz1);for(vector<T>&t:a)t.resize(sz2,v);}
	template<typename T>void assign(vector<T>&a,int sz1,const T&v){a.assign(sz1,v);}
	template<typename T>void assign(vector<vector<T>>&a,int sz1,int sz2,const T&v){a.resize(sz1);for(vector<T>&t:a)t.assign(sz2,v);}
	template<typename T,size_t SZ>void fill(array<T,SZ>&a,const T&v){std::fill(ALL(a),v);}
	template<typename T,size_t SZ1,size_t SZ2>void fill(array2<T,SZ1,SZ2>&a,const T&v){for(array<T,SZ2>&t:a)std::fill(ALL(t),v);}
	template<typename T,typename U>ostream&operator<<(ostream&os,const pair<T,U>&pr){os<<"{"<<pr.first<<","<<pr.second<<"}";return os;}
	template<typename T>ostream&operator<<(ostream&os,vector<T>&a){for(int i=0;i<a.size();i++){if(i!=0){os<<" ";}os<<a[i];}return os;}
	template<typename T>ostream&operator<<(ostream&os,const vector<T>&a){for(int i=0;i<a.size();i++){if(i!=0){os<<" ";}os<<a[i];}return os;}
	template<typename T,size_t SZ>ostream&operator<<(ostream&os,const array<T,SZ>&a){os<<"[";for(int i=0;i<SZ;i++){if(i!=0){os<<",";}os<<a[i];}os<<"]";return os;}
	template<typename T,typename U>ostream&operator<<(ostream&os,const map<T,U>&m){os<<"{";auto b=m.begin();auto e=m.end();for(auto p=b;p!=e;++p){if(p!=b){os<<",";}os<<p->first<<":"<<p->second;}os<<"}";return os;}
	template<typename T>ostream&operator<<(ostream&os,const set<T>&s){os<<"{";auto b=s.begin();auto e=s.end();for(auto p=b;p!=e;++p){if(p!=b){os<<",";}os<<*p;}os<<"}";return os;}
	template<typename T,typename U>ostream&operator<<(ostream&os,const unordered_map<T,U>&m){os<<"{";auto b=m.begin();auto e=m.end();for(auto p=b;p!=e;++p){if(p!=b){os<<",";}os<<p->first<<":"<<p->second;}os<<"}";return os;}
	template<typename T>ostream&operator<<(ostream&os,const unordered_set<T>&s){os<<"{";auto b=s.begin();auto e=s.end();for(auto p=b;p!=e;++p){if(p!=b){os<<",";}os<<*p;}os<<"}";return os;}
	constexpr ll mod_add(ll a,ll b,ll mod){return((a%mod)+(b%mod))%mod;}
	constexpr ll mod_sub(ll a,ll b,ll mod){return((a%mod)+mod-(b%mod))%mod;} // a>bだとmod-(b-a)が返る
	constexpr ll mod_mul(ll a,ll b,ll mod){return((a%mod)*(b%mod))%mod;}
	constexpr ull mod_add(ull a,ull b,ull mod){return((a%mod)+(b%mod))%mod;}
	constexpr ull mod_sub(ull a,ull b,ull mod){return((a%mod)+mod-(b%mod))%mod;} // a>bだとmod-(b-a)が返る
	constexpr ull mod_mul(ull a,ull b,ull mod){return((a%mod)*(b%mod))%mod;}
	constexpr int intPow(int x,int n){assert(x>=0);assert(n>=0);if(x==0){if(n==0){return 1;}else{return 0;}}int r=1,z=x;while(n>0){if(n&1){r*=z;}z*=z;n>>=1;}return r;}
	constexpr ll intPow(ll x,ll n){assert(x>=0ll);assert(n>=0ll);if(x==0ll){if(n==0ll){return 1ll;}else{return 0ll;}}ll r=1ll,z=x;while(n>0ll){if(n&1ll){r*=z;}z*=z;n>>=1ll;}return r;}
	//constexpr ll intPow(ll x,ll n,ll mod){assert(x>=0ll);assert(n>=0ll);if(x==0ll){if(n==0ll){return 1ll;}else{return 0ll;}}ll r=1ll,z=x;while(n>0ll){if(n&1ll){if(mod>0ll){r=mod_mul(r,z,mod);}else{r*=z;}}if(mod>0ll){z=mod_mul(z,z,mod);}else{z*=z;}n>>=1ll;}return r;}
	constexpr ll intPow(ll x,ll n,ll mod){
		assert(x>=0ll);
		assert(n>=0ll);
		if(x==0ll){
			if(n==0ll){
				return 1ll;
			}else{
				return 0ll;
			}
		}
		ll r=1ll,z=x;
		while(n>0ll){
			if(n&1ll){
				r*=z;
				r%=mod;
			}
			z*=z;
			z%=mod;
			n>>=1ll;
		}
		return r;
	}
	constexpr ull intPow(ull x,ull n){if(x==0ull){if(n==0ull){return 1ull;}else{return 0ull;}}ull r=1ull,z=x;while(n>0ull){if(n&1ull){r*=z;}z*=z;n>>=1ull;}return r;}
	constexpr ull intPow(ull x,ull n,ull mod){if(x==0ull){if(n==0ull){return 1ull;}else{return 0ull;}}ull r=1ull,z=x;while(n>0ull){if(n&1ull){if(mod>0ull){r=mod_mul(r,z,mod);}else{r*=z;}}if(mod>0ull){z=mod_mul(z,z,mod);}else{z*=z;}n>>=1ull;}return r;}
	constexpr ll mod_inv(ll a,ll mod){return intPow(a%mod,mod-2ll,mod);}
	constexpr ll mod_div(ll a,ll b,ll mod){return mod_mul(a,mod_inv(b,mod),mod);}
	constexpr ull mod_inv(ull a,ull mod){return intPow(a%mod,mod-2ull,mod);}
	constexpr ull mod_div(ull a,ull b,ull mod){return mod_mul(a,mod_inv(b,mod),mod);}
	typedef pair<int, int> pii;
	typedef pair<ll, ll> pll;
	typedef pair<long double, long double> pdd;
	ll ceilDiv(ll a,ll b){return a/b+(a%b!=0?1:0);}
	ll isOverflowAdd(ll a,ll b){return a>V_LL_MAX-b;}
	ll isOverflowMul(ll a,ll b){return a>V_LL_MAX/b;}

	void debugErrSub(){cerr<<endl;}
	template<class Head,class...Tail>void debugErrSub(Head&&head,Tail&&...tail){cerr<<" "<<head;debugErrSub(std::forward<Tail>(tail)...);}
	template<class Head,class...Tail>void debugErr(Head&&head,Tail&&...tail){cerr<<head;debugErrSub(std::forward<Tail>(tail)...);}

	template<typename Key, typename Value>
	bool containsKey(const umap<Key, Value>& m, const Key& key) {
		return m.find(key) != m.end();
	}
	template<typename Key, typename Value>
	bool containsValue(const umap<Key, Value>& m, const Value& val) {
		for (auto it = m.begin(); it != m.end(); ++it)
			if (it->second == val)
				return true;
		return false;
	}
	template<typename T>
	const typename uset<T>::const_iterator find(const uset<T>& s, const T& key) {
		return s.find(key);
	}
	template<typename T>
	bool contains(const uset<T>& s, const T& key) {
		return s.find(key) != s.end();
	}

#ifndef __GNUC__
	int __builtin_popcount(unsigned int n){return(int)bitset<32>(n).count();}
	int __builtin_popcountll(unsigned long long n){return(int)bitset<64>(n).count();}
#endif

	template<typename T>string strConcat(const vector<T>&strList,const string&separator){stringstream s;for(int i=0;i<(int)strList.size();++i){if(i>0){s<<separator;}s<<strList[i];}return move(s.str());}
	string trimLeft(const string&str,char ch){int len=(int)str.length();for(int i=0;i<len;++i){if(str[i]!=ch){return str.substr(i);}}return "";}
	string trimRight(const string&str,char ch){int len=(int)str.length();for(int i=len-1;i>=0;--i){if(str[i]!=ch){return str.substr(0,i+1);}}return "";}
	string planeDouble(double val,int prec){assert(prec>=0);stringstream ss;ss<<fixed<<setprecision(prec)<<val;return move(ss.str());}
	string fillZero(ll num,int digit){int zeroNum=max(0,(int)(digit-to_string(num).length()));return move(move(string(zeroNum,'0'))+move(to_string(num)));}

	ull xor128(){static ull x=123456789,y=362436069,z=521288629,w=88675123;ull t=(x^(x<<11));x=y;y=z;z=w;return w=(w^(w>>19))^(t^(t>>8));}

	// lb: lower bound. 条件式を満たさない
	// ub: upper bound. 条件式を満たす
	// check: 条件式
	ll binarySearch(ll lb, ll ub, const function<bool(const ll&)>& check) {

		while (abs(ub - lb) > 1ll) {
			ll mid = (lb + ub) / 2ll;
			if (check(mid)) {
				ub = mid;
			} else {
				lb = mid;
			}
		}

		return ub;
	}

	// 最大公約数（ユーグリッドの互除法）
	static constexpr ull gcd(ull x, ull y) {
		assert(x > 0ull);
		assert(y > 0ull);
		ull r = 0ull;
		while ((r = x % y) != 0ull) {
			x = y;
			y = r;
		}
		return y;
	}

	// 最小公倍数
	static constexpr ull lcm(ull x, ull y) {
		assert(x > 0ull);
		assert(y > 0ull);

		return x / gcd(x, y) * y;
	}

	// 素因数分解 O(√n)
	// 1のとき、1を返す。2以上のとき、2以上の素因数を全て返す
	int calcDecompositPrime(vector<ll>* primes, ll n) {
		primes->clear();
		if (n == 0) {
			return 0ll;
		}
		if (n == 1) {
			primes->push_back(1);
			return 1ll;
		}
		// 割る数の初期値
		ll a = 2ll;
		// √n ≧ a ( n ≧ a * a ) の間ループ処理
		while (n >= a * a) {
			if (n % a == 0ll) {
				// a で割り切れたら、a は素因数
				primes->push_back(a);
				// そして、割られる数を a で割る
				n /= a;
			} else {
				// a で割り切れなかったら、 a を 1 増加させる
				++a;
			}
		}
		primes->push_back(n);
		return (int)primes->size();
	}

	template<typename A>void in(A&a){cin>>a;cin.ignore();}
	template<typename A,typename B>void in(A&a,B&b){cin>>a>>b;cin.ignore();}
	template<typename A,typename B,typename C>void in(A&a,B&b,C&c){cin>>a>>b>>c;cin.ignore();}
	template<typename A,typename B,typename C,typename D>void in(A&a,B&b,C&c,D&d){cin>>a>>b>>c>>d;cin.ignore();}
	template<typename A,typename B,typename C,typename D,typename E>void in(A&a,B&b,C&c,D&d,E&e){cin>>a>>b>>c>>d>>e;cin.ignore();}
	template<typename A,typename B,typename C,typename D,typename E,typename F>void in(A&a,B&b,C&c,D&d,E&e,F&f){cin>>a>>b>>c>>d>>e>>f;cin.ignore();}
	template<typename A,typename B,typename C,typename D,typename E,typename F,typename G>void in(A&a,B&b,C&c,D&d,E&e,F&f,G&g){cin>>a>>b>>c>>d>>e>>f>>g;cin.ignore();}

	template<typename A>void inr(vector<A>&a,int size){resize(a,size);for(int i=0;i<size;++i){cin>>a[i];cin.ignore();}}
	template<typename A,typename B>void inr(vector<A>&a,vector<B>&b,int size){resize(a,size);resize(b,size);for(int i=0;i<size;++i){cin>>a[i]>>b[i];cin.ignore();}}
	template<typename A,typename B,typename C>void inr(vector<A>&a,vector<B>&b,vector<C>&c,int size){resize(a,size);resize(b,size);resize(c,size);for(int i=0;i<size;++i){cin>>a[i]>>b[i]>>c[i];cin.ignore();}}
	template<typename A,typename B,typename C,typename D>void inr(vector<A>&a,vector<B>&b,vector<C>&c,vector<D>&d,int size){resize(a,size);resize(b,size);resize(c,size);resize(d,size);for(int i=0;i<size;++i){cin>>a[i]>>b[i]>>c[i]>>d[i];cin.ignore();}}
	template<typename A,typename B,typename C,typename D,typename E>void inr(vector<A>&a,vector<B>&b,vector<C>&c,vector<D>&d,vector<E>&e,int size){resize(a,size);resize(b,size);resize(c,size);resize(d,size);resize(e,size);for(int i=0;i<size;++i){cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];cin.ignore();}}

	template<typename A>void inrl(vector<A>&a,int size){resize(a,size);for(int i=0;i<size;++i){cin>>a[i];}cin.ignore();}

	template<typename A>void inr(vector2<A>&a,int h,int wa){resize(a,h,wa);for(int i=0;i<h;++i){for(int j=0;j<wa;++j){cin>>a[i][j];}cin.ignore();}}
	template<typename A,typename B>void inr(vector2<A>&a,vector2<B>&b,int h,int wa,int wb){resize(a,h,wa);resize(b,h,wb);for(int i=0;i<h;++i){for(int j=0;j<wa;++j){cin>>a[i][j];}for(int j=0;j<wb;++j){cin>>b[i][j];}cin.ignore();}}
	template<typename A,typename B,typename C>void inr(vector2<A>&a,vector2<B>&b,vector2<C>&c,int h,int wa,int wb,int wc){resize(a,h,wa);resize(b,h,wb);resize(c,h,wc);for(int i=0;i<h;++i){for(int j=0;j<wa;++j){cin>>a[i][j];}for(int j=0;j<wb;++j){cin>>b[i][j];}for(int j=0;j<wc;++j){cin>>c[i][j];}cin.ignore();}}

	template<typename A,typename B>void inpr(vector<pair<A,B>>&a,int h){resize(a,h);for(int i=0;i<h;++i){cin>>a[i].first>>a[i].second;cin.ignore();}}

	template<typename T>void out(const T&val){cout<<val<<"\n";}
}

using namespace ValLib;

static constexpr int COMBI_MAX = 1000000; // nCrのnとrの最大値
static ull gFact[COMBI_MAX + 1]; // modの世界での階乗
static ull gInv[COMBI_MAX + 1]; // modの世界での逆元
static ull gFactInv[COMBI_MAX + 1]; // modの世界での逆元の階乗
static ull gCombiInitMod = 0; // 組み合わせの計算に使用したmod値
static int gCombiInitCnt = 0; // 組み合わせの計算をいくつまでやったか

// 組み合わせテーブルを作る
static void initCombination(int combiMax, ull mod) {
	assert(combiMax <= COMBI_MAX);
	if (mod != gCombiInitMod) {
		gCombiInitCnt = 0;
	}
	if (gCombiInitCnt == 0) {
		gFact[0] = gFact[1] = 1;
		gFactInv[0] = gFactInv[1] = 1;
		gInv[1] = 1;
		gCombiInitCnt = 1;
	}
	for (int i = gCombiInitCnt + 1; i <= COMBI_MAX; i++){
		gFact[i] = gFact[i - 1] * i % mod;
		gInv[i] = mod - gInv[mod%i] * (mod / i) % mod;
		gFactInv[i] = gFactInv[i - 1] * gInv[i] % mod;
	}
	gCombiInitMod = mod;
	gCombiInitCnt = combiMax;
}
static void initCombination(ull mod) {
	initCombination(COMBI_MAX, mod);
}
static void initCombination() {
	initCombination(COMBI_MAX, V_MOD);
}
ll mod_div2(ull a,int b,ull mod) {
	if (mod != gCombiInitMod || gCombiInitMod < gCombiInitCnt) {
		initCombination(b, mod);
	}
	return mod_mul(a, gInv[b], mod);
}

// 組み合わせの数を計算
static long long combination(ull n, ull k, ull mod) {
	assert(gCombiInitMod > 0 && "先にinitCombinationを呼び出して");
	assert(n <= (ull)gCombiInitCnt);
	assert(k <= (ull)gCombiInitCnt);
	if (n < k) return 0;
	return (gFact[n] * ((gFactInv[k] * gFactInv[n - k]) % mod)) % mod;
}

// 重複組合せ nHr = n+r-1Cr
// 使いどころ：n人にr個を配るとき、同じ人に何個配っても良い場合とか
// 4人に5個の◯を配るときa=2,b=0,c=2,d=1のとき、◯◯||◯◯|◯みたいになる。
// これは◯と|を混ぜた組み合わせで、◯の数がn,棒の数はr-1だから全体でn+r-1
// (n-r)で割ったものが順列n+r-1Prで、それを更にrで割っているからnHr = n+r-1Cr
static ull repeatedCombination(ull n, ull r, ull mod) {
	return combination(n + r - 1, r, mod);
}

void solve() {

	int W, H;
	in(W, H);
	initCombination(1000000007ll);
	out(combination(W + H - 2, W - 1, 1000000007ll));

}

int main() {
	std::ios::sync_with_stdio(false);

	//ifstream ifs("input01.txt");
	//cin.rdbuf(ifs.rdbuf());

	//ofstream ofs("output01.txt");
	//cout.rdbuf(ofs.rdbuf());

	solve();
}
