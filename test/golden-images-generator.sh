#!/bin/bash
# generate golden images
EXECUTE=../build/MIA/bin/MIA
GOLDENDIR=golden-images
GOLDENSEQ=$GOLDENDIR/brainstack
TESTDIR=test-images
PHOTOPATH=../resources/test-images
SEQPATH=$PHOTOPATH/brainstack

$EXECUTE $PHOTOPATH/brainColor.jpg $GOLDENDIR/brainColor.png
$EXECUTE $PHOTOPATH/brainColor.jpg $GOLDENDIR/brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -sharpen 5.0 $GOLDENDIR/sharpen-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -edge $GOLDENDIR/edge-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -threshold 0.8 $GOLDENDIR/threshold-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -quantize 4 $GOLDENDIR/quantize-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -blur 7.0 $GOLDENDIR/blur-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -saturate 0.0 $GOLDENDIR/saturate-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -channel 0.5 0.5 0.5 $GOLDENDIR/channel-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -edge -channel 0.5 0.5 0.5 $GOLDENDIR/edge-channel-brainColor.jpg
$EXECUTE $PHOTOPATH/brainColor.jpg -quantize 4 -sharpen 5.0 -channel 0.5 0.5 0.5 $GOLDENDIR/quantize-sharpen-channel-brainColor.png


$EXECUTE $PHOTOPATH/graphWithoutAlpha.png $GOLDENDIR/graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png $GOLDENDIR/graphWithoutAlpha.jpg
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -sharpen 5.0 $GOLDENDIR/sharpen-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -edge $GOLDENDIR/edge-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -threshold 0.8 $GOLDENDIR/threshold-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -quantize 4 $GOLDENDIR/quantize-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -blur 7.0 $GOLDENDIR/blur-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -saturate 0.0 $GOLDENDIR/saturate-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -channel 0.5 0.5 0.5 $GOLDENDIR/channel-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -edge -channel 0.5 0.5 0.5 $GOLDENDIR/edge-channel-graphWithoutAlpha.png
$EXECUTE $PHOTOPATH/graphWithoutAlpha.png -quantize 4 -sharpen 5.0 -channel 0.5 0.5 0.5 $GOLDENDIR/quantize-sharpen-channel-graphWithoutAlpha.jpg

$EXECUTE $SEQPATH/mrbrain-8bit###.png -channel 0.3 0.6 0.9 -edge $GOLDENSEQ/output###.jpg
