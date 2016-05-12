function cleanOrbit {
  local deltav is ship:facing:vector:normalized.
  local timeout is time:seconds + 9000.
  lock steering to lookdirup(deltav, ship:facing:topvector).
  set th to 0.

  until deltav:mag < 0.2 or time:seconds > timeout {
    set vecnormal to vcrs(up:vector,velocity:orbit).
    set vechorizontal to -1 * vcrs(up:vector, vecnormal).
    set vechorizontal:mag to sqrt(body:mu/(body:radius + altitude)).
    set deltav to vechorizontal - velocity:orbit.

    if vang(ship:facing:vector,deltav) > 1 {
      lock throttle to 0.
    } else {
      lock throttle to max(0,min(1,deltav:mag/10)).
    }
  }
  lock throttle to 0.
  lock steering to lookdirup(srfretrograde:vector, ship:facing:topvector).
  output (green,"Orbit is clean").
}

function deorbit {
  lock steering to lookdirup(srfretrograde:vector, ship:facing:topvector).
  wait 10.
  lock throttle to 1.

  until stage:liquidfuel < 0.1 or ship:periapsis < 20000 {
    wait 0.5.
  }

  lock throttle to 0.
  wait 1.
  output(green,"Stage " + stage:number + " seperation").
  stage.
}

function waitForDeorbit {
  until alt:radar < 5000 {
    wait 0.5.
  }
  output(green,"Parashoot ready").
  stage.
  until alt:radar < 1000 {
    wait 0.5.
  }
}
print "loading orbit.inc".
