Intro
-----

In 2011, construction started on the replacement for a major bridge
that I can see from my house, and I wanted to make a longform
time-lapse video of the project.

Since the project would be several years in duration, I needed an
imaging solution that would be as hands free as possible, but, I also
wanted to be able to generate HD quality video.

So I decided to mount a Canon 40D on one of my windows.

I bought a DS8111 power adapter to obviate the need to change
batteries, but I also realized, even with very large CF cards, that it
would be tyranny to have to regularly change them out.
I looked into ways I could control the camera remotely and pull images
directly from the camera, but unfortunately, at the time, everything
I found was GUI-based.

I wanted something that was command-line driven so that I could run it
in a cronjob on a headless Mac Mini with a large USB drive attached.

This project resulted.


Building
-----

Unfortunately, you won't be able to build this project out of the box.
It requires Canon's binary SDK which I cannot legally post.

The process of obtaining the SDK is fairly straightforward;
read about it [here](https://www.developersupport.canon.com/faq/366#t366n4258).

Once you have the SDK, unfurl it inside the toplevel directory.
You should have an EDSDK folder.

Then, simply:

``` bash
$ make
```

which, if all goes well, will leave you with a file called<br>
<code>./eosctrl.app/Contents/MacOS/eosctrl</code> .

Usage
-----

The eosctrl program does nothing more than take a shot and retrieve
the image data from the camera.<br>
Any settings of aperature and modes etc. are done manually on the
camera.

In my case, I set the camera to aperture priority mode at f/5.6,
allowing the camera to decide how long to keep the shutter open.

``` bash
$ ./eosctrl.app/Contents/MacOS/eosctrl filename
```

This will

- <p>search for a camera on USB</p>
- <p>talk to the first camera it finds and tell it to take a shot</p>
- <p>create either filename.JPG, filename.CR2, or both in the current working directory, depending on the shooting mode of the camera.</p>

Caveats
-----

For the long term workflow, I would have preferred to power up the
camera, take a shot, and then power down the camera.

To automate the power cycling, I had a friend build an IP-based electrical
switch using an Arduino, a relay, and some other parts.
The switch worked great, but the camera's actions in powering up were
rather unpredictable.
Sometimes the camera even would lock up the bus in a way that would require
the host computer to be rebooted.

Lacking the tools to debug that, I decided to simply keep the camera
running all the time.
The amount of power it would consume while idle would pale in comparison
to the power consumed energizing the sensor.

However, this wasn't stable either: after the camera has been on for a
certain amount of time -- or perhaps after taking a certain number of
shots, I never did figure that out -- it would simply lock up.

The final solution was to buy a cheap analog timer and simply
reboot the camera once a day at an irrelevant time.

After that low-tech innovation, the system would stay running for
months at a time without interruption.


Sample Output
-----

Output should look something like this:

```
$ ./eosctrl.app/Contents/MacOS/eosctrl asd
State holder has address 0xf5194
Camera found: 0x7cb77e00
Starting event loop
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Received kEdsPropertyEvent_PropertyDescChanged property event
Failed to get property UNKNOWN property: EDS_ERR_PROPERTIES_UNAVAILABLE
Property kEdsPropID_ProductName has type=kEdsDataType_String,size=32
Property kEdsPropID_ProductNamehas value Canon EOS 40DProperty kEdsPropID_BodyID has type=kEdsDataType_UInt32,size=4
Property kEdsPropID_OwnerName has type=kEdsDataType_String,size=1
Property kEdsPropID_OwnerNamehas value Failed to get property kEdsPropID_MakerName: EDS_ERR_PROPERTIES_UNAVAILABLE
Property kEdsPropID_DateTime has type=kEdsDataType_Time,size=28
Property kEdsPropID_FirmwareVersion has type=kEdsDataType_String,size=32
Property kEdsPropID_FirmwareVersionhas value 1.0.3Property kEdsPropID_BatteryLevel has type=kEdsDataType_Int32,size=4
Failed to get property kEdsPropID_CFn: EDS_ERR_NOT_SUPPORTED
Property kEdsPropID_SaveTo has type=kEdsDataType_UInt32,size=4
Property kEdsPropID_CurrentStorage has type=kEdsDataType_String,size=16
Property kEdsPropID_CurrentStoragehas value CFProperty kEdsPropID_CurrentFolder has type=kEdsDataType_String,size=16
Property kEdsPropID_CurrentFolderhas value 442CANONProperty kEdsPropID_MyMenu has type=kEdsDataType_UInt32_Array,size=24
Failed to get property kEdsPropID_BatteryQuality: EDS_ERR_PROPERTIES_UNAVAILABLE
Failed to get property kEdsPropID_HDDirectoryStructure: EDS_ERR_NOT_SUPPORTED
Setting SaveTo
Current value of kEdsPropID_SaveTo is 2
Opened session
Locking camera
Locked camera
Taking picture
Unlocking camera
Unlocked camera
Waiting for frames
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsPropertyEvent_PropertyChanged property event
Received kEdsStateEvent_JobStatusChanged state event
Received kEdsPropertyEvent_PropertyChanged property event
Handling kEdsObjectEvent_DirItemRequestTransfer event
Download of asd.CR2 complete, setting framecount to 1
Finished waiting for frames
Received 1 frames, shutting down
Closing session
Received kEdsStateEvent_JobStatusChanged state event
Session is closed
Terminating SDK
Terminated SDK


```






