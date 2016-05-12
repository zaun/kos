set terminal:width to 51.
set terminal:height to 30.
set logs to list(list(0,""),list(0,""),list(0,""),list(0,""),list(0,""),list(0,""),list(0,""),list(0,""),list(0,""),list(0,"")).
set hudtime to 0.

function addLog {
  parameter text.
  logs:remove(0).
  logs:add(list(round(missiontime),text)).
}

function output {
  parameter color.
  parameter text.
  hudtext(text,2,2,42,color,false).
  addLog(text).
}

function startHud {
  print "===================================================" at (0,1).
  print "   Sea  Level    |   Down Range   |      Orbit     " at (0,2).
  print "    Altitude     |    Distance    |   Inclination  " at (0,3).
  print "                 |                |                " at (0,4).
  print "-----------------+----------------+----------------" at (0,5).
  print "    Apoapsis     |   Periapsis    |Thrust to Weight" at (0,6).
  print "                 |                |                " at (0,7).
  print "                 |                |                " at (0,8).
  print "-----------------+----------------+----------------" at (0,9).
  print "     Fuel        |      Ship      |                " at (0,10).
  print "                 |                |                " at (0,11).
  print "                 |                |                " at (0,12).
  print "                 |                |                " at (0,13).
  print "===================================================" at (0,14).

  when round(missiontime) - hudtime > 1 then {
    set hudtime to round(missiontime).
    // print "altitude: " + round(alt:radar) + "  " at (0,0).

    set engInfo to engineInfoActive().
    set curTWR to "Cur: " + round(engInfo[0]/(ship:mass*body:mu/(altitude+body:radius)^2),2).
    set maxTWR to "Max: " + round(engInfo[1]/(ship:mass*body:mu/(altitude+body:radius)^2),2).
    set seaLevelAlt to round(alt:radar/1000,2)+"km".
    set downRangeDist to SQRT(launchLoc:Distance^2 - (altitude - launchAlt)^2).
    set downRangeDist to round(downRangeDist/1000,2)+"km".
    set obtInclination to round(ship:obt:inclination,1)+"km".
    set apo to round(apoapsis/1000,2)+"km".
    set per to round(periapsis/1000,2)+"km".
    set apoE to round(eta:apoapsis) + "s".
    set perE to round(eta:periapsis) + "s".
    print "                 |                |                " at (0,4).
    print seaLevelAlt at (8-seaLevelAlt:length/2,4).
    print downRangeDist at (25-downRangeDist:length/2,4).
    print obtInclination at (42-obtInclination:length/2,4).

    print "                 |                |                " at (0,7).
    print "                 |                |                " at (0,8).
    print apo at (8-apo:length/2,7).
    print apoE at (8-apoE:length/2,8).
    print per at (25-per:length/2,7).
    print perE at (25-perE:length/2,8).
    print curTWR at (42-curTWR:length/2,7).
    print maxTWR at (42-maxTWR:length/2,8).

    print "                 |                |                " at (0,11).
    print "                 |                |                " at (0,12).
    print "                 |                |                " at (0,13).
    print " Elec:   " + round(ship:electriccharge) at (0,11).
    print " Solid:  " + round(stage:solidfuel) at (0,12).
    print " Liquid: " + round(stage:liquidfuel) at (0,13).
    print " Stage:  " + stage:number at (18,11).
    print " Mass:   " + round(ship:mass,2) at (18,12).

    print "-----------------------[log]-----------------------" at (0,18).
    print "[t+" + round(missiontime) + "]" at (1,18).
    print "[" + ship:status + "]" at (48 - ship:status:length,18).
    from {local x is 20.} until x = 30 step {set x to x+1.} do {
      print ")                                                 (" at (0,x-1).
      if logs[x-20][1] <> "" {
        print "t+" + logs[x-20][0] at (2,x-1).
        print logs[x-20][1] at (10,x-1).
      }
    }
    return true.
  }
}

print "loading hud.inc".
