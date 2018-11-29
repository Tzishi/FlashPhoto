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
allgene=1
allsame=1

echo "--------------test of running: generating test images...-------------------"

$EXECUTE $PHOTOPATH/brainColor.jpg $TESTDIR/brainColor.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg $TESTDIR/brainColor.png"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg $TESTDIR/brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg $TESTDIR/brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 $TESTDIR/sharpen-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 $TESTDIR/sharpen-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -edge $TESTDIR/edge-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -edge $TESTDIR/edge-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -threshold 0.8 $TESTDIR/threshold-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -threshold 0.8 $TESTDIR/threshold-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -quantize 4 $TESTDIR/quantize-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -quantize 4 $TESTDIR/quantize-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -blur 7.0 $TESTDIR/blur-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -blur 7.0 $TESTDIR/blur-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -saturate 0.0 $TESTDIR/saturate-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -saturate 0.0 $TESTDIR/saturate-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -channel 0.5 0.5 0.5 $TESTDIR/channel-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -channel 0.5 0.5 0.5 $TESTDIR/channel-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -edge -channel 0.5 0.5 0.5 $TESTDIR/edge-channel-brainColor.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -edge -channel 0.5 0.5 0.5 $TESTDIR/edge-channel-brainColor.jpg"
fi

$EXECUTE $PHOTOPATH/brainColor.jpg -quantize 4 -sharpen 5.0 -channel 0.5 0.5 0.5 $TESTDIR/quantize-sharpen-channel-brainColor.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/brainColor.jpg -quantize 4 -sharpen 5.0 -channel 0.5 0.5 0.5 $TESTDIR/quantize-sharpen-channel-brainColor.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png $TESTDIR/graphWithoutAlpha.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png $TESTDIR/graphWithoutAlpha.jpg"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png $TESTDIR/graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png $TESTDIR/graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -sharpen 5.0 $TESTDIR/sharpen-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -sharpen 5.0 $TESTDIR/sharpen-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -edge $TESTDIR/edge-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -edge $TESTDIR/edge-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -threshold 0.8 $TESTDIR/threshold-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -threshold 0.8 $TESTDIR/threshold-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -quantize 4 $TESTDIR/quantize-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -quantize 4 $TESTDIR/quantize-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -blur 7.0 $TESTDIR/blur-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -blur 7.0 $TESTDIR/blur-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -saturate 0.0 $TESTDIR/saturate-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -saturate 0.0 $TESTDIR/saturate-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -channel 0.5 0.5 0.5 $TESTDIR/channel-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -channel 0.5 0.5 0.5 $TESTDIR/channel-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -edge -channel 0.5 0.5 0.5 $TESTDIR/edge-channel-graphWithoutAlpha.png
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -edge -channel 0.5 0.5 0.5 $TESTDIR/edge-channel-graphWithoutAlpha.png"
fi

$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -quantize 4 -sharpen 5.0 -channel 0.5 0.5 0.5 $TESTDIR/quantize-sharpen-channel-graphWithoutAlpha.jpg
if [ $? -eq 0 ]
then echo "generate image successfully"
else echo "fail to execute: $EXECUTE $PHOTOPATH/graphWithoutAlpha.png -quantize 4 -sharpen 5.0 -channel 0.5 0.5 0.5 $TESTDIR/quantize-sharpen-channel-graphWithoutAlpha.jpg"
fi

$EXECUTE $SEQPATH/mrbrain-8bit###.png -channel 0.3 0.6 0.9 -edge $TESTSEQ/output###.jpg
if [ $? -eq 0 ]
then echo "generate sequence images successfully"
else echo "fail to execute: $EXECUTE $SEQPATH/mrbrain-8bit###.png -channel 0.3 0.6 0.9 -edge $TESTSEQ/output###.jpg"
fi

echo "-------------test filters: compare the result of commands----------------"

$EXECUTE $PHOTOPATH/brainColor.jpg -compare $PHOTOPATH/graphWithoutAlpha.png
echo $?
if [ $? -eq 1 ]
then echo "compare single image doesn't work"; exit 1
fi
$EXECUTE $PHOTOPATH/brainColor.jpg -compare $PHOTOPATH/brainColor.jpg
if [ $? -eq 1 ]
then echo "compare single image works well"
else echo "compare single image doesn't work"; exit 1
fi
$EXECUTE $SEQPATH/mrbrain-8bit###.png -compare $TESTSEQ/output###.jpg
echo $?
if [ $? -eq 1 ]
then echo "compare sequence images doesn't work"; exit 1
fi
$EXECUTE $SEQPATH/mrbrain-8bit###.png -compare $SEQPATH/mrbrain-8bit###.png
if [ $? -eq 1 ]
then echo "compare sequence images works well"
else echo "compare sequence images doesn't work"; exit 1
fi




list=$(cd golden-images; ls -1)
for i in $list ; do
	if [ "$i" != "brainstack" ]
	then $EXECUTE $GOLDENDIR/$i -compare $TESTDIR/$i
	else $(exit 1)
	fi
	if [ $? -ne 1 ]
	then echo "$GOLDENDIR/$i and $TESTDIR/$i are different, do something!!!"
	fi
done

list=$(cd golden-images/brainstack; ls -1)
for i in $list ; do
	$EXECUTE $GOLDENSEQ/$i -compare $TESTSEQ/$i
	if [ $? -ne 1 ]
	then echo "$GOLDENSEQ/$i and $TESTSEQ/$i are different, do something!!!"
	fi
done

echo "------------done-------------"
