import React, { Component } from "react";
import Tilt from "react-tilt";

export class Team extends Component {
  render() {
    return (
      <div id="team" className="text-center">
        <div className="container">
          <div className="col-xs-12 col-md-8 col-md-offset-2 section-title">
            <h2>Conoce al equipo</h2>
            <p>
              "Una familia que trabaja unida, permanece unida"
            </p>
          </div>
          <div id="row">
            {this.props.data
              ? this.props.data.map((d, i) => (
                  <div  key={`${d.name}-${i}`} className="col-xs-12 col-md-12 col-sm-12 team">
                    <div className="thumbnail">
                      {" "}
                      <Tilt className="Tilt" options={{ max : 10 }}  >
                      <div className="Tilt-inner"> <img src={d.img} alt="..." className="team-img" /> </div>
                      </Tilt> 
                      
                      <div className="caption">
                        <h4>{d.name}</h4>
                        <p>{d.job}</p>
                      </div>
                    </div>
                  </div>
                ))
              : "loading"}
          </div>
        </div>
      </div>
    );
  }
}

export default Team;
