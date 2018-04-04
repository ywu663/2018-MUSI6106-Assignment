# CMake generated Testfile for 
# Source directory: /Users/Yi/Desktop/2018-MUSI6106-exercise_2
# Build directory: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RingBuff "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/TestExec" "RingBuff")
add_test(Fft "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/TestExec" "Fft")
add_test(AudioIo "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/TestExec" "AudioIo" "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/src/Tests/TestData/")
add_test(CombFilter "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/TestExec" "CombFilter")
add_test(Dtw "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/TestExec" "Dtw")
add_test(Vibrato "/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/TestExec" "Vibrato")
subdirs("MUSI6106Exec")
subdirs("AudioFileIO")
subdirs("CombFilter")
subdirs("Fft")
subdirs("Dtw")
subdirs("Vibrato")
subdirs("TestExec")
