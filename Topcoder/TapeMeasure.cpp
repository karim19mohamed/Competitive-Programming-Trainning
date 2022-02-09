#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> point;
//#define endl '\n'
#define F first
#define S second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define FOR(sz) for(int i = 0; i < sz; ++i)
#define dbg_array(x,sz) FOR(sz) cerr << x[i] << " \n"[i==sz-1]
#define X real()
#define Y imag()

const int d4i[4] = { -1, 0, 1, 0 }, d4j[4] = { 0, 1, 0, -1 };
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, d8j[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

template<typename T_n> void read(T_n &n) {
	cin >> n;
}
template<typename T_n, typename T_a> void read(T_a a[], T_n n) {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
template<typename T_n, typename T_a> void read(vector<T_a> &a, T_n n) {
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
void _init_() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ECLIPSE
	freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);
#endif
}

const int N = 1e3 + 9, M = 1e5 + 9;
const int Mod_M = 1e9 + 7;

class TapeMeasure {
public:
	vector<string> draw(int leftMark, int rightMark) {
		vector<string> ans;
		int sz = rightMark - leftMark + 1;
		sz = 2 * sz - 1;
		string s(sz, '#');
		ans.push_back(s);
		for (int i = 1; i < sz; i += 2)
			s[i] = ' ';
		ans.push_back(s);
		int idx = leftMark;
		string s2(sz, ' ');
		for (int i = 0; i < sz; i += 2, idx++)
			if (idx % 5 == 0) s2[i] = '#';
		ans.push_back(s2);

		idx = leftMark;
		string s3(sz, ' ');
		for (int i = 0; i < sz; i += 2, idx++)
			if (idx % 10 == 0) s3[i] = '#';
		ans.push_back(s3);

		idx = leftMark;
		string s4(sz, ' ');
		if ((leftMark - 1) > 99 && (leftMark - 1) % 10 == 0) {
			string tmp = to_string((leftMark - 1) % 10);
			s4[0] = tmp[0];
		}
		for (int i = 0; i < sz; i += 2, idx++)
			if (idx % 10 == 0) {
				string tmp = to_string(idx);
				for (int j = i; j < sz && j - i < (int) tmp.size(); j++)
					s4[j] = tmp[j - i];
			}
		ans.push_back(s4);
		return ans;
	}
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
using std::string;
using std::vector;
int run_test_case(int);
void run_test(int casenum = -1, bool quiet = false) {
	if (casenum != -1) {
		if (run_test_case(casenum) == -1 && !quiet) {
			std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
		}
		return;
	}

	int correct = 0, total = 0;
	for (int i = 0;; ++i) {
		int x = run_test_case(i);
		if (x == -1) {
			if (i >= 100) break;
			continue;
		}
		correct += x;
		++total;
	}

	if (total == 0) {
		std::cerr << "No test cases run." << std::endl;
	} else if (correct < total) {
		std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
	} else {
		std::cerr << "All " << total << " tests passed!" << std::endl;
	}
}

template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) {
	os << "{";
	for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) {
		if (vi != v.begin()) os << ",";
		os << " " << *vi;
	}
	os << " }";
	return os;
}
template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) {
	os << "{";
	for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) {
		if (vi != v.begin()) os << ",";
		os << " \"" << *vi << "\"";
	}
	os << " }";
	return os;
}

int verify_case(int casenum, const vector<string> &expected, const vector<string> &received, std::clock_t elapsed) {
	std::cerr << "Example " << casenum << "... ";

	string verdict;
	vector<string> info;
	char buf[100];

	if (elapsed > CLOCKS_PER_SEC / 200) {
		std::sprintf(buf, "time %.2fs", elapsed * (1.0 / CLOCKS_PER_SEC));
		info.push_back(buf);
	}

	if (expected == received) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}

	std::cerr << verdict;
	if (!info.empty()) {
		std::cerr << " (";
		for (size_t i = 0; i < info.size(); ++i) {
			if (i > 0) std::cerr << ", ";
			std::cerr << info[i];
		}
		std::cerr << ")";
	}
	std::cerr << std::endl;

	if (verdict == "FAILED") {
		std::cerr << "    Expected: " << expected << std::endl;
		std::cerr << "    Received: " << received << std::endl;
	}

	return verdict == "PASSED";
}

int run_test_case(int casenum__) {
	switch (casenum__) {
	case 0: {
		int leftMark = 0;
		int rightMark = 25;
		string expected__[] = { "###################################################",

		"# # # # # # # # # # # # # # # # # # # # # # # # # #", "#         #         #         #         #         #",
				"#                   #                   #          ", "0                   10                  20         " };

		std::clock_t start__ = std::clock();
		vector<string> received__ = TapeMeasure().draw(leftMark, rightMark);
		return verify_case(casenum__, vector<string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])),
				received__, clock() - start__);
	}
	case 1: {
		int leftMark = 981;
		int rightMark = 990;
		string expected__[] = { "###################", "# # # # # # # # # #", "        #         #", "                  #",
				"0                 9" };

		std::clock_t start__ = std::clock();
		vector<string> received__ = TapeMeasure().draw(leftMark, rightMark);
		return verify_case(casenum__, vector<string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])),
				received__, clock() - start__);
	}
	case 2: {
		int leftMark = 20;
		int rightMark = 20;
		string expected__[] = { "#", "#", "#", "#", "2" };

		std::clock_t start__ = std::clock();
		vector<string> received__ = TapeMeasure().draw(leftMark, rightMark);
		return verify_case(casenum__, vector<string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])),
				received__, clock() - start__);
	}
	case 3: {
		int leftMark = 31;
		int rightMark = 38;
		string expected__[] = { "###############", "# # # # # # # #", "        #      ", "               ", "               " };

		std::clock_t start__ = std::clock();
		vector<string> received__ = TapeMeasure().draw(leftMark, rightMark);
		return verify_case(casenum__, vector<string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])),
				received__, clock() - start__);
	}

		// custom cases

		/*      case 4: {
		 int leftMark              = ;
		 int rightMark             = ;
		 string expected__[]       = ;

		 std::clock_t start__      = std::clock();
		 vector <string> received__ = TapeMeasure().draw(leftMark, rightMark);
		 return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		 }*/
		/*      case 5: {
		 int leftMark              = ;
		 int rightMark             = ;
		 string expected__[]       = ;

		 std::clock_t start__      = std::clock();
		 vector <string> received__ = TapeMeasure().draw(leftMark, rightMark);
		 return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		 }*/
		/*      case 6: {
		 int leftMark              = ;
		 int rightMark             = ;
		 string expected__[]       = ;

		 std::clock_t start__      = std::clock();
		 vector <string> received__ = TapeMeasure().draw(leftMark, rightMark);
		 return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		 }*/
	default:
		return -1;
	}
}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i = 1; i < argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
