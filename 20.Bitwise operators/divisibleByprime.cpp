#include<iostream>
using namespace std;

#define ll long long 

int main(){
    ll t;
    cin>>t;

    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    while(t--){
    	ll n;
    	cin>>n;
        
        ll subsets = (1<<8) - 1;
        ll ans = 0;

        for(ll i=1;i<=subsets;i++){
        	ll demon = 1ll;
        	ll setBits = __builtin_popcount(i);

        	for(ll j=0;j<=7;j++){
        		if(i&(1<<j)){
        			demon = demon * primes[j];
        		}
        	}
        	if(setBits&1){
        		ans += n/demon;
        	}
        	else{
        		ans -= n/demon;
        	}
        }
        cout<<ans<<endl;

    }

	return 0;
}