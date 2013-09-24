int main() {
	Vec3 n = vec31,1,0.normalized();
	Tensor4 tens = makeTetragonalTensor(5.6e10, 5.145e10, 2.2e10, 10.6e10, 2.65e10, 6.6e10);
	Mat3 chrMat = christoffel(tens, n);
	vector<SolPart> sols = solveChristoffel(chrMat);
}