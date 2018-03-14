The "Phoenix 3" rocket -- Takeoff and land again

Recently, we had the thrill of seeing the spectacular Falcon 9 Heavy launch and its incredible landing. It's time for Elon not to be alone at this feat and for others to honestly just have fun following in his shoes. I intend to make a rocket that will ascend under its own propulsion and return to Earth for a soft vertical landing. I will accomplish this using a retropropulsion and suicide burn deceleration method after reaching apogee. All flight systems will be internally controlled and Phoenix 3 will have a full array of telemetry and data logging capacity for future development through complete data analysis from previous launches. It will be approximately 76 cm tall (not including the payload fairing) and 7.6 cm in diameter, weighing about 1 kg.

I expect this project to in total take approximately one and a half years before a proper landing and full reusability is accomplished. Although the project may last for over a year, an average flight will be much shorter. The total time of a flight will be approximately 1 minute and 20 seconds from ignition to booster landing. The timeline of a launch will be as follows with an abort being possible all the way up to main engine ignition:

T  -3:10: Internal systems receive full control of flight  
T - 3:07: Guidance calibration  
T  -3:05: Flight control testing  
T  -3:00: 3 minute wait period for evacuation  
T  -0:01: Main engine ignition  
T +0:00: Lift off  
T +0:03: Main engine cut off  
T +0:07: Apogee, fairing jettison  
T +0:08: Descent control propulsion startup  
T +1:15: Full deceleration for landing  
T +1:17: Landing legs deploy  
T +1:20: Landing and shutdown  

The ascent will be achieved with three Estes class 'E' solid rocket engines and will have full aerodynamic control over all 3 axis of flight to maintain a proper trajectory to apogee. All flight computer and software will run on an Arduino Due and will be programed using Arduino C. Apogee will be at approximately 350 meters and likely directly above the range. At this point, the ascent fins will stow and wait to be re-deployed as landing legs. The rate of descent will be controlled with a model aircraft motor and propeller unit and the trajectory will be maintained using a further set of guidance fins. There will also be a set of fins that are meant to counter the rotational moment of the propellor. When near the ground, Phoenix 3 will decelerate to a near stop and deploy its landing legs for a soft landing. Telemetry will consist of a compass, a barometer, an accelerometer, and a gyroscope.

I have already selected all the necessary parts and have started to write the guidance navigation and control software. Also, I have done significant research on the topic but have had limited success in finding good resources on the relatively small scale that I am discussing. It appears that no one has successfully used retropropulsion and a suicide burn to land a model rocket but there is always a first. I have much experience with aerodynamics and basic guidance navigation and control in the context of model aircraft. These skills along with a relatively good programming background may be enough to accomplish this. The first step is to achieve a stable ascent and a successful fairing jettison and afterwards, the landing may be attempted. Although the chances of success are low, as Elon Musk said, "Failure is an option here. If things are not failing, you are not innovating enough."

For my progress and further plans including blueprints and a parts list, see:  
-   <https://github.com/BLehrer99/Landing-A-Model-Rocket>

For reference, see:  
-   Allain, Rhett. "The Physics of SpaceX's Wicked Double Booster Landing." Wired. February 08, 2018. Accessed March 13, 2018. <https://www.wired.com/story/the-physics-of-spacex-falcon-heavy-wicked-double-booster-landing/>  
-   "Surviving a Suicide Burn." Gaming With PHYSICS. Accessed March 13, 2018. <http://ffden-2.phys.uaf.edu/webproj/211_fall_2016/Samual_Green/Samual_Green/blog_0.html>  
-   "AHRS for Adafruit's 9-DOF, 10-DOF, LSM9DS0 Breakouts." Introduction | AHRS for Adafruit's 9-DOF, 10-DOF, LSM9DS0 Breakouts | Adafruit Learning System. Accessed March 13, 2018. <https://learn.adafruit.com/ahrs-for-adafruits-9-dof-10-dof-breakout/introduction>  
-   <http://www2.estesrockets.com/pdf/Estes_Engine_Chart.pdf>  
-   "Model rocket." Wikipedia. March 09, 2018. Accessed March 13, 2018. <https://en.wikipedia.org/wiki/Model_rocket>  
-   Spacexchannel. "How Not to Land an Orbital Rocket Booster." YouTube. September 14, 2017. Accessed March 13, 2018. <https://www.youtube.com/watch?v=bvim4rsNHkQ>  
-   "SpaceX Launch You Up (Uptown Funk Parody)." YouTube. November 01, 2017. Accessed March 13, 2018. https://youtu.be/NY7N02eZGoQ
