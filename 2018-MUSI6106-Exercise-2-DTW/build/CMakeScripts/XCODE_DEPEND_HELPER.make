# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.MUSI6106Exec.Debug:
PostBuild.Fft.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec
PostBuild.CombFilter.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec
PostBuild.Vibrato.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec
PostBuild.AudioFileIO.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec
PostBuild.sndlib.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/MUSI6106Exec


PostBuild.AudioFileIO.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libAudioFileIO.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libAudioFileIO.a


PostBuild.sndlib.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libsndlib.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libsndlib.a


PostBuild.CombFilter.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libCombFilter.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libCombFilter.a


PostBuild.Fft.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libFft.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libFft.a


PostBuild.Dtw.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libDtw.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libDtw.a


PostBuild.Vibrato.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libVibrato.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libVibrato.a


PostBuild.TestExec.Debug:
PostBuild.UnitTest++.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
PostBuild.Fft.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
PostBuild.CombFilter.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
PostBuild.Dtw.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
PostBuild.Vibrato.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
PostBuild.AudioFileIO.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
PostBuild.sndlib.Debug: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libUnitTest++.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libDtw.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/debug/TestExec


PostBuild.UnitTest++.Debug:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libUnitTest++.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libUnitTest++.a


PostBuild.MUSI6106Exec.Release:
PostBuild.Fft.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec
PostBuild.CombFilter.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec
PostBuild.Vibrato.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec
PostBuild.AudioFileIO.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec
PostBuild.sndlib.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/MUSI6106Exec


PostBuild.AudioFileIO.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libAudioFileIO.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libAudioFileIO.a


PostBuild.sndlib.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libsndlib.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libsndlib.a


PostBuild.CombFilter.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libCombFilter.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libCombFilter.a


PostBuild.Fft.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libFft.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libFft.a


PostBuild.Dtw.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libDtw.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libDtw.a


PostBuild.Vibrato.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libVibrato.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libVibrato.a


PostBuild.TestExec.Release:
PostBuild.UnitTest++.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
PostBuild.Fft.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
PostBuild.CombFilter.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
PostBuild.Dtw.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
PostBuild.Vibrato.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
PostBuild.AudioFileIO.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
PostBuild.sndlib.Release: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libUnitTest++.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libDtw.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/release/TestExec


PostBuild.UnitTest++.Release:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libUnitTest++.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libUnitTest++.a


PostBuild.MUSI6106Exec.MinSizeRel:
PostBuild.Fft.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec
PostBuild.CombFilter.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec
PostBuild.Vibrato.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec
PostBuild.AudioFileIO.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec
PostBuild.sndlib.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/MUSI6106Exec


PostBuild.AudioFileIO.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libAudioFileIO.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libAudioFileIO.a


PostBuild.sndlib.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libsndlib.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libsndlib.a


PostBuild.CombFilter.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libCombFilter.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libCombFilter.a


PostBuild.Fft.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libFft.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libFft.a


PostBuild.Dtw.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libDtw.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libDtw.a


PostBuild.Vibrato.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libVibrato.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libVibrato.a


PostBuild.TestExec.MinSizeRel:
PostBuild.UnitTest++.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
PostBuild.Fft.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
PostBuild.CombFilter.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
PostBuild.Dtw.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
PostBuild.Vibrato.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
PostBuild.AudioFileIO.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
PostBuild.sndlib.MinSizeRel: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libUnitTest++.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libDtw.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/MinSizeRel/TestExec


PostBuild.UnitTest++.MinSizeRel:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libUnitTest++.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libUnitTest++.a


PostBuild.MUSI6106Exec.RelWithDebInfo:
PostBuild.Fft.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec
PostBuild.CombFilter.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec
PostBuild.Vibrato.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec
PostBuild.AudioFileIO.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec
PostBuild.sndlib.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/MUSI6106Exec


PostBuild.AudioFileIO.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libAudioFileIO.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libAudioFileIO.a


PostBuild.sndlib.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libsndlib.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libsndlib.a


PostBuild.CombFilter.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libCombFilter.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libCombFilter.a


PostBuild.Fft.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libFft.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libFft.a


PostBuild.Dtw.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libDtw.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libDtw.a


PostBuild.Vibrato.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libVibrato.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libVibrato.a


PostBuild.TestExec.RelWithDebInfo:
PostBuild.UnitTest++.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
PostBuild.Fft.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
PostBuild.CombFilter.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
PostBuild.Dtw.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
PostBuild.Vibrato.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
PostBuild.AudioFileIO.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
PostBuild.sndlib.RelWithDebInfo: /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec:\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libUnitTest++.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libFft.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libCombFilter.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libDtw.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libVibrato.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libAudioFileIO.a\
	/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libsndlib.a
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/bin/relwithdebinfo/TestExec


PostBuild.UnitTest++.RelWithDebInfo:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libUnitTest++.a:
	/bin/rm -f /Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libUnitTest++.a




# For each target create a dummy ruleso the target does not have to exist
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libAudioFileIO.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libCombFilter.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libDtw.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libFft.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libUnitTest++.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libVibrato.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/MinSizeRel/libsndlib.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libAudioFileIO.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libCombFilter.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libDtw.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libFft.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libUnitTest++.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libVibrato.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/debug/libsndlib.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libAudioFileIO.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libCombFilter.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libDtw.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libFft.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libUnitTest++.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libVibrato.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/release/libsndlib.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libAudioFileIO.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libCombFilter.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libDtw.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libFft.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libUnitTest++.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libVibrato.a:
/Users/Yi/Desktop/2018-MUSI6106-exercise_2/lib/relwithdebinfo/libsndlib.a:
