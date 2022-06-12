import React, { Component } from "react";
import Tilt from "react-tilt";

export class Services extends Component {
  render() {
    return (
      <div id="services" className="text-center">
        <div className="container">
          <div className="section-title">
            <h2>¿Qué Ofrecemos?</h2>
            {/* <p>
              A continuación te presentamos los diferentes servicios que somos capaces de 
            </p> */}
          </div>
          <div className="row">
            {this.props.data
              ? this.props.data.map((d, i) => (
                  <div  key={`${d.name}-${i}`} className="col-md-4">
                    {" "}
                      <Tilt className="Tilt" options={{ max : 10 }}  >
                      <div className="Tilt-inner"> <i className={d.icon}></i> </div>
                      </Tilt> 
                    <div className="service-desc">
                      <h3>{d.name}</h3>
                      <p>{d.text}</p>
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

export default Services;
