import React, { Component } from "react";

export class Navigation extends Component {
  render() {
    return (
      <nav id="menu" className="navbar navbar-default navbar-fixed-top">
        <div className="container">
          <div className="navbar-header">
            <button
              type="button"
              className="navbar-toggle collapsed"
              data-toggle="collapse"
              data-target="#bs-example-navbar-collapse-1"
            >
              {" "}
              <span className="sr-only">Toggle navigation</span>{" "}
              <span className="icon-bar"></span>{" "}
              <span className="icon-bar"></span>{" "}
              <span className="icon-bar"></span>{" "}
            </button>
            <a className="navbar-brand page-scroll" href="#page-top">
              NEXTNGNR
              {/* <div class="logo-img-navbar">
              <img
                        src="img/newportfolio/nextngnrlogo.png"
                        className="img-fluid"
                      />
              </div> */}
            </a>{" "}
            
          </div>

          <div
            className="collapse navbar-collapse"
            id="bs-example-navbar-collapse-1"
          >
            <ul className="nav navbar-nav navbar-right">
              <li>
                <a href="#features" className="page-scroll">
                  Pilares
                </a>
              </li>
              <li>
                <a href="#about" className="page-scroll">
                  Nosotros
                </a>
              </li>
              <li>
                <a href="#services" className="page-scroll">
                  Servicios
                </a>
              </li>
              <li>
                <a href="#portfolio" className="page-scroll">
                  Galería
                </a>
              </li>
              <li>
                <a href="#testimonials" className="page-scroll">
                  Testimonios
                </a>
              </li>
              <li>
                <a href="#team" className="page-scroll">
                  Equipo
                </a>
              </li>
              <li>
                <a href="#contact" className="page-scroll">
                  Contáctenos
                </a>
              </li>
            </ul>
          </div>
        </div>
      </nav>
    );
  }
}

export default Navigation;
