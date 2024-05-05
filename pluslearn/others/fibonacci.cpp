#include <iostream>
#include <map>


long fib(int n) {
   static std::map<int,int> cache{ {0,0}, {1,1} }; 

   auto found = cache.find(n);

   if (found != std::end(cache)) {
       return found->second;
   }

   long result = fib(n-1) + fib(n-2);
   cache[n] = result;
   return result;

}


int main() {
    int n = 40;

    for(int i=1; i<= n; i++) {
        std::cout << fib(i) << " ";
    }
}
