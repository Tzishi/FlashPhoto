#!/bin/bash
# test functinalities.
# brainColor.jpg graphWithoutAlpha.png and brainstack photoes are used for testing.
# We assume that golden images are already generated.
EXECUTE=../build/MIA/bin/MIA
GOLDENDIR=golden-images
GOLDENSEQ=$GOLDENDIR/brainstack
TESTDIR=test-images
TESTSEQ=$TESTDIR/brainstack
PHOTOPATH=../resources/test-images
SEQPATH=$PHOTOPATH/brainstack

output=$($EXECUTE -h test-bad-input)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE -h test-bad-input"
fi

output=$($EXECUTE -comparec -h)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE -comparec -h"
fi

output=$($EXECUTE input.jp output.png)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE -comparec -h"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 10 10 $TESTDIR/brainColor.jpg)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 10 10 $TESTDIR/brainColor.jpg"
fi

output=$($EXECUTE input.jpg -h )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE input.jpg -h "
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 4 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 4 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE -sharpen 5.0 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE -sharpen 5.0 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 "
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 -edge 4 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 -edge 4 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brasinColor.jpg -sharpen 5.0 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 -edge 4 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -channal 5.0 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -channal 5.0 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -channal 1.0 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -channal 1.0 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -channal 1.0 0 0 0 0 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -channal 1.0 0 0 0 0 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -edge 0 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -edge 0 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainCoklor.jpg -edge $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -edge 0 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -threshold 1 2 $TESTDIR/sharpen-brainColor.hjpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -threshold 1 2 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -quantize 1 2 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -quantize 1 2 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -quantize 2.5 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -quantize 2.5 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $PHOTOPATH/brainColor.jpg -blur1 1 2.5 $TESTDIR/sharpen-brainColor.jpg )
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $PHOTOPATH/brainColor.jpg -blur1 1 2.5 $TESTDIR/sharpen-brainColor.jpg"
fi

output=$($EXECUTE $SEQPATH/mrbrain###.png -channel 0.3 0.6 0.9 -edge $TESTSEQ/output###.jpg)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $SEQPATH/mrbrain-8it###.png -channel 0.3 0.6 0.9 -edge $TESTSEQ/output###.jpg"
fi

output=$($EXECUTE $SEQPATH/mrbrain-8bit##.pnga -channel 0.3 0.6 0.9 -edge $TESTSEQ/output###.jpg)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $SEQPATH/mrbrain-8it##.png -channel 0.3 0.6 0.9 -edge $TESTSEQ/output###.jpg"
fi

output=$($EXECUTE $SEQPATH/mrbrain-8bit##.pnga -channel 0.3 0.6 0.9 -edge)
if [ $? -eq 0 ]
then echo "fail to detect $EXECUTE $SEQPATH/mrbrain-8bit##.png -channel 0.3 0.6 0.9 -edge"
fi

output=$($EXECUTE $SEQPATH/mrbrain-8bit##.pnga -channel 0.3 0.6 0.9 -edge)
if [ $? -eq 0 ]
then echo "fail to detect -channel 0.3 0.6 0.9 -edge"
fi
