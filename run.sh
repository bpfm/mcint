# clang++ -Xpreprocessor -fopenmp -L /usr/local/opt/llvm/lib -lomp  main.cpp func1D.cpp integrate1D.cpp func2D.cpp integrate2D.cpp func3D.cpp integrate3D.cpp integrate3DAlpha.cpp alphaAnalytic.cpp perturberExtended.cpp alphaExtended.cpp -O3 -o mcint
# ./mcint

# gcc  main.cpp func1D.cpp integrate1D.cpp func2D.cpp integrate2D.cpp func3D.cpp integrate3D.cpp integrate3DAlpha.cpp alphaAnalytic.cpp perturberExtended.cpp alphaExtended.cpp integrate3DTest.cpp integrate2DAlpha.cpp -O3 -o mcint
# ./mcint

gcc main.cpp func1D.cpp func2D.cpp func3D.cpp integrate1D.cpp integrateMean1D.cpp integrate2D.cpp integrateMean2D.cpp integrate3D.cpp integrateMean3D.cpp integrate2DAlpha.cpp integrateMean2DAlpha.cpp integrateMean2DSPAlpha.cpp integrate3DAlpha.cpp integrateMean3DAlpha.cpp alphaExtended.cpp alphaAnalytic.cpp perturberExtended.cpp -O3 -o mcint
./mcint