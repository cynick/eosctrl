#!/bin/bash -x

export LAFAYETTE_DIR=/images/lafeyette
export LAST_FILE="last.txt";
export EOSCTRL=eosctrl

export EOSCTRL_CMD=/Users/worm/eosctrl/eosctrl.app/Contents/MacOS/eosctrl

format-next-name () {   
    local name=$1;
    next=$(perl -e "\$a=q{$name}; \$a=~s/IMG_0*//;printf qq{IMG_%08d},(\$a +1)");
    echo -n $next
}

fast-find-next-name() { 
    
    local dir=$LAFAYETTE_DIR;
    local lastFile=$LAST_FILE;
    
    if [ ! -d $dir ];
        then echo "Image directory $dir does not exist";
        return;
    fi
    
    (cd $dir;
        if [ -f "$lastFile" ]; then 
            local last=$(cat $lastFile);
            echo -n $(format-next-name ${last%%.*})
            return;
        fi
    )
    
    echo -n "";
}

find-next-name() { 
    local name=$(fast-find-next-name);

    if [ ! -z $name ];then
        echo -n $name;
        return;
    fi

    local max=0;
    for f in $(find $LAFAYETTE_DIR -type f | grep -v *.txt ); do
        a=$(basename $f);
        b=${a/IMG_/};
        c=${b%%.*}; 
        if [ $c -gt $max ];then max=$b;fi;
    done
    
    echo -n $(format-next-name);
}
      
warn() { 
    :;
}

shoot() { 

    local name=$(find-next-name);
    if [ -z $name ]; then
        echo "Could not find next name!"
        return;
    fi
    
    #$EOSCTRL_CMD $name 2;
    touch $LAFAYETTE_DIR/${name}.JPG;
    
    echo $name > $LAFAYETTE_DIR/last.txt;

    if [ ! -f $name ]; then
        warn $name;
    fi;

}


shoot;