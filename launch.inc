function countdown {
  for t in range(10, 0) {
    bigNum(5,5,t).
    wait 1.
  }
}

function launch {
  lock throttle to 1.
  stage.
  if stage:solidfuel > 0 {
    output(green,"SRB Ignition").
  } else {
    output (green,"Stage " + stage:number + " ignition").
  }
}

// the higher up the ship is, the more it is
// pitched over
function gravTurn {
  parameter st. // start turn
  parameter et. // end turn

  sas off.
  set ar to alt:radar.

  if ar > st {
    set pda to (-1 * (sqrt(0.05 * ar))).
    set pitchvector to (r(0, pda, 0) * up).
    lock steering to lookdirup(pitchvector:vector, ship:facing:topvector).
  }
  if ar > et  {
    lock steering to lookdirup(prograde:vector, ship:facing:topvector).
    return true.
  }
  return false.
}

function waitForOrbit {
  until ship:periapsis > 90000 and ship:apoapsis > 90000 {
    // save some power
    wait 0.5.
  }
  output (green,"In orbit").
  lock throttle to 0.
}

function launchOneStage {
  parameter orbit.

  set gtf to false.  // gravity turn finished
  until gtf = true {
    if gtf = false and gravTurn(1000, orbit) = true {
      output (green,"Gravity turn finished").
      set gtf to true.
    }
    // save some power
    wait 0.1.
  }
  waitForOrbit.
}

function launchTwoStage {
  parameter fuelType.
  parameter orbit.

  set gtf to false.  // gravity turn finished
  set sf to false.   // stage finished
  until gtf = true and sf = true {
    set fuel to stage:solidfuel.
    if fuelType = "liquid" {
      set fuel to stage:liquidfuel.
    }

    if sf = false and fuel < 0.1 {
      set sf to true.
      output(green,"Stage " + stage:number + " seperation").
      stage.
      wait 2.
      output(green,"Stage " + stage:number + " ignition").
      stage.
    }

    if gtf = false and gravTurn(1000, orbit) = true {
      output (green,"Gravity turn finished").
      set gtf to true.
    }
    // save some power
    wait 0.1.
  }
  waitForOrbit.
}

set launchLoc to ship:geoposition.
set launchAlt to ALTITUDE.
print "loading launch.inc".
