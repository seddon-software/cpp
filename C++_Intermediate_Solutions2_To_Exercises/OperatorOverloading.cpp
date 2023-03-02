/*******************************************************************
 *
 * Operator Overloading
 *
 ******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix(vector<vector<int>> m): m(m), rows(m.size()), cols(m[0].size()) {}
	Matrix(): m({ {{}} }), rows(0), cols(0) {}
	int getRows() const { return rows; }
	int getCols() const { return cols; }

	void print()
	{
		for(auto v: m)
		{
			for(auto i: v)
			{
				cout << i << ",";
			}
			cout << endl;
		}
	}
	void empty(int rows, int cols)
	{
		Matrix empty;
		(empty.m).resize(rows);
		for(int row = 0; row < rows; row++)
		{
			(empty.m)[row].resize(cols);
		}
		empty.rows = rows;
		empty.cols = cols;
		*this = empty;
	}

	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs)
	{
		Matrix result(lhs);
		for(int row = 0; row < lhs.rows; row++)
		{
			for(int col = 0; col < lhs.cols; col++)
			{
				(result.m)[row][col] += (rhs.m)[row][col];
			}
		}
		return result;
	}
	friend Matrix operator-(const Matrix& lhs, const Matrix& rhs)
	{
		Matrix result(lhs);
		for(int row = 0; row < lhs.rows; row++)
		{
			for(int col = 0; col < lhs.cols; col++)
			{
				(result.m)[row][col] -= (rhs.m)[row][col];
			}
		}
		return result;
	}

	void transpose()
	{
		vector<vector<int>> self;

		for(int col = 0; col < cols; col++)
		{
			vector<int> v;
			for(int row = 0; row < rows; row++)
			{
				v.push_back(m[row][col]);
			}
			self.push_back(v);
		}
		rows = self.size();
		cols = self[0].size();
		m = self;

	}

	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs)
	{
		Matrix rhs2(rhs);
		rhs2.transpose();
		int rows = lhs.getRows();
		int cols = rhs2.getCols();
		Matrix result;
		result.empty(rows, cols);

		vector<int> v1, v2;

		for(int row = 0; row < result.rows; row++)
		{
			for(int col = 0; col < result.cols; col++)
			{
				v1 = lhs.m[row];
				v2 = rhs2.m[col];
				for(unsigned i = 0; i < v1.size(); i++)
				{
					(result.m)[row][col] += v1[i] * v2[i];
				}
			}
		}
		return result;
	}
private:
	vector<vector<int>> m;
	int rows;
	int cols;
};

int main()
{
	Matrix product;
	Matrix a = { {{1,2,3},{4,5,6}} };
	Matrix b = { {{10,20},{30,40},{50,60}} };
	product = a * b;
	product.print();
	cout << endl;

	Matrix m1{ {{11,12,13},{21,22,23}, {31,32,33}, {41,42,43}} };
	Matrix m2{ {{2,3,4},{5,6,7}, {9,8,7}, {10,2,4}} };
	m1.transpose();
	m1.print();
	cout << endl;
	m1.transpose();
	m1.print();
	cout << endl;

	Matrix m = m1 + m2;
	m.print();
}
