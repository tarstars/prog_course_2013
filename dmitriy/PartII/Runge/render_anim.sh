#!/bin/sh
# ==============================================================================
# POV-Ray 3.7 
# render_anim.sh - render a scene scene as animation
# ==============================================================================
# written November 2003 by Christoph Hormann
# This file is part of POV-Ray and subject to the POV-Ray licence
# see POVLEGAL.DOC for details
# ------------------------------------------------------------------------------
# calling conventions:
#
#   render_anim.sh scene_file 1/dt [output_directory]
#
# output_directory: directory where to write the rendered images and animation 
# scene_file: scene to render
#
# if an ini file with the same basename as the scene_file exists this is
# used for rendering the animation.  Otherwise the render options have to be 
# given as a '//' comment within the first 50 lines of the file.  There must 
# be a space after the '//' and the first option has to start with '-' or '+'.  
# 
# The scene is rendered into a set of png files and then compiled to an mpeg 
# using ffmpeg (which has to be available in PATH).  The png files are deleted 
# afterwards if the animation has been generated successfully.
# ==============================================================================

# --- specify additional render options here ---
POV_OPTIONS="+W800 +H640"

FFMPEG=`which ffmpeg`

if [ ! -z "$1" ] ; then
    RENDER_NAME="$1"
else
    echo "scene_file dt [output_directory]"
    exit 1
fi

if [ ! -z "$2" ] ; then
    DT=$2
else
    echo "scene_file 1/dt [output_directory]"
    exit 1
fi

if [ ! -z "$3" ] ; then
    OUTPUT_DIR="$3"
    rm -f $OUTPUT_DIR/*.png
else
    OUTPUT_DIR=`dirname $1`
fi

SCENE_DIR=`dirname $RENDER_NAME`
FILE_BASE=`basename $RENDER_NAME .pov`

if [ -f "$SCENE_DIR/$FILE_BASE.ini" ] ; then
    INI_FILE="$SCENE_DIR/$FILE_BASE.ini"
fi

if [ ! -z "$INI_FILE" ] ; then

    echo "==========================================================================="
    echo "$INI_FILE"
    echo "==========================================================================="
    
    echo "povray +L$SCENE_DIR $INI_FILE -o$OUTPUT_DIR/ $POV_OPTIONS -p +fn"
    povray +L$SCENE_DIR $INI_FILE -o$OUTPUT_DIR/ $POV_OPTIONS -p +fn > /dev/null

else

    head -n 50 "$RENDER_NAME" | grep -E '^//[ ]+[-+]{1}[^ -]' > /dev/null && POV_FILE="$RENDER_NAME"

    if [ ! -z "$POV_FILE" ] ; then
        # -- use first option line --
        OPTIONS=`head -n 50 "$POV_FILE" | grep -E '^//[ ]+[-+]{1}[^ -]' | head -n 1 | sed "s?^//[ ]*??"`
        # -- use last option line --
        #OPTIONS=`head -n 50 "$POV_FILE" | grep -E '^//[ ]+[-+]{1}[^ -]' | tail -n 1 | sed "s?^//[ ]*??"`

        echo "==========================================================================="
        echo "$POV_FILE: $OPTIONS"
        echo "==========================================================================="
    
        echo "povray +L$SCENE_DIR -i$POV_FILE -o$OUTPUT_DIR/ $OPTIONS $POV_OPTIONS -p +fn"
        povray +L$SCENE_DIR -i$POV_FILE -o$OUTPUT_DIR/ $OPTIONS $POV_OPTIONS -p +fn > /dev/null

    fi
fi

PNG_NAME=`find $OUTPUT_DIR -path "$OUTPUT_DIR/$FILE_BASE*.png" | head -n 1`
PNG_FILE_BASE=`basename $PNG_NAME`  

OCNT=`echo "$FILE_BASE.png" | wc -c`
CCNT=`echo "$PNG_FILE_BASE" | wc -c`
NCNT=`expr $CCNT - $OCNT`

if [ ! -z "$FFMPEG" ] ; then
    case $NCNT in
        1 | 2 | 3 | 4 )
            echo "-------------- compiling animation using ffmpg --------------"

            if [[ $DT > 30 ]]; then
                echo "-------------- frame rate limited to 30fps     --------------"
                ffmpeg -i "$OUTPUT_DIR/$FILE_BASE%${NCNT}d.png" -vcodec mpeg4 -r 30 "$OUTPUT_DIR/$FILE_BASE.mpg"
            else
                echo "-------------- frame rate is $DT fps          --------------"
                ffmpeg -i "$OUTPUT_DIR/$FILE_BASE%${NCNT}d.png" -vcodec mpeg4 -r $DT "$OUTPUT_DIR/$FILE_BASE.mpg"
            fi
            echo "-------------- finished compiling animation -----------------"
            if [ -f "$OUTPUT_DIR/$FILE_BASE.mpg" ] ; then
                rm -f $OUTPUT_DIR/$FILE_BASE*.png
            fi
        ;;
    esac
fi

