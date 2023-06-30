#include <stdio.h>
#include <iostream>
#include <vector>


int contiguous_sequence(std::vector<int> &v);

int main()
{
	 /* ?\n;||(or) e &&(and)*/

	std::vector<int> v1 = {2,-8,3,-2,4,-10};
	std::vector<int> v2 = {5,-10,1,2,3,-11};
	std::cout << contiguous_sequence(v1) << '\n';
	std::cout << contiguous_sequence(v2) << '\n';

	return 0;
}

int contiguous_sequence(std::vector<int> &v){

	/*The idea is to make the cumulative sum,and when the increment to next index is negative if curr is the current sum
	 * curr + v[i] < 0 then stop and make curr a sum the start couting from v[i+1],else just continue continue,after all this
	 * check the biggest sum
	 */

	int curr = v[0];
	int max = 0;
	for(int i = 1;i < v.size();i++){

		if(v[i] + curr > 0){
			curr += v[i];
			if(curr >= max){
				max = curr;
			}
		}
		else if(v[i] + curr <= 0){
			if(curr >= max){
				max = curr;
			}
			curr = 0;
		}

	}

	return max;

}
